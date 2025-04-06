// SPDX-License-Identifier: GPL-2.0
/*
 * gc2053 sensor driver
 *
 * Copyright (C) 2020 Rockchip Electronics Co., Ltd.
 *
 * V0.0X01.0X00 first version.
 * V0.0X01.0X01 add quick stream on/off
 */

#include <linux/clk.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/i2c.h>
#include <linux/module.h>
#include <linux/pm_runtime.h>
#include <linux/of.h>
#include <linux/of_graph.h>
#include <linux/regulator/consumer.h>
#include <linux/sysfs.h>
#include <linux/slab.h>
#include <linux/pinctrl/consumer.h>
#include <linux/version.h>
#include <linux/rk-camera-module.h>

#include <media/v4l2-async.h>
#include <media/media-entity.h>
#include <media/v4l2-common.h>
#include <media/v4l2-ctrls.h>
#include <media/v4l2-device.h>
#include <media/v4l2-event.h>
#include <media/v4l2-fwnode.h>
#include <media/v4l2-image-sizes.h>
#include <media/v4l2-mediabus.h>
#include <media/v4l2-subdev.h>

#define DRIVER_VERSION          KERNEL_VERSION(0, 0x01, 0x01)
#define GC2053_NAME             "gc2053"
#define GC2053_MEDIA_BUS_FMT    MEDIA_BUS_FMT_SGRBG10_1X10

#define MIPI_FREQ_297M          297000000
#define GC2053_XVCLK_FREQ       24000000

#define GC2053_PAGE_SELECT      0xFE

#define GC2053_REG_CHIP_ID_H    0xF0
#define GC2053_REG_CHIP_ID_L    0xF1

#define GC2053_REG_EXP_H        0x03
#define GC2053_REG_EXP_L        0x04

#define GC2053_REG_VTS_H        0x41
#define GC2053_REG_VTS_L        0x42

#define GC2053_REG_CTRL_MODE    0x3E
#define GC2053_MODE_SW_STANDBY  0x11
#define GC2053_MODE_STREAMING   0x91

#define REG_NULL                0xFF

#define GC2053_CHIP_ID          0x2053

#define GC2053_VTS_MAX          0x3FFF
#define GC2053_HTS_MAX          0xFFF

#define GC2053_EXPOSURE_MAX     0x3FFF
#define GC2053_EXPOSURE_MIN     1
#define GC2053_EXPOSURE_STEP    1

#define GC2053_GAIN_MIN         0x40
#define GC2053_GAIN_MAX         0x2000
#define GC2053_GAIN_STEP        1
#define GC2053_GAIN_DEFAULT     64

#define GC2053_LANES            2

#define OF_CAMERA_PINCTRL_STATE_DEFAULT "rockchip,camera_default"
#define OF_CAMERA_PINCTRL_STATE_SLEEP   "rockchip,camera_sleep"

#define SENSOR_ID(_msb, _lsb)   ((_msb) << 8 | (_lsb))

#define GC2053_FLIP_MIRROR_REG  0x17

#define GC_MIRROR_BIT_MASK      BIT(0)
#define GC_FLIP_BIT_MASK        BIT(1)

static const char * const gc2053_supply_names[] = {
	"dovdd",    /* Digital I/O power */
	"avdd",     /* Analog power */
	"dvdd",     /* Digital core power */
};

#define GC2053_NUM_SUPPLIES ARRAY_SIZE(gc2053_supply_names)

#define to_gc2053(sd) container_of(sd, struct gc2053, subdev)

enum gc2053_max_pad {
	PAD0,
	PAD_MAX,
};

struct regval {
	u8 addr;
	u8 val;
};

struct gc2053_mode {
	u32 width;
	u32 height;
	struct v4l2_fract max_fps;
	u32 hts_def;//存储模式的水平总大小的默认值，它通常包括一行中所有的像素，包括可见图像和额外的填充像素。
	u32 vts_def;//存储模式的垂直总大小的默认值，它表示一帧图像中的总行数，包括所有可见图像和额外的垂直填充行。
	u32 exp_def;//存储模式的曝光时间的默认值，用于定义传感器捕获图像时光线照射传感器的时间长度。
	const struct regval *reg_list;
	u32 hdr_mode;
	u32 vc[PAD_MAX];//存储了每个数据通道（PAD）的配置信息。PAD_MAX 是一个宏，定义了可能的最大通道数。
};

struct gc2053 {
	struct i2c_client   *client;//I2C客户端
	struct clk      *xvclk;//用于传感器的时钟资源
	struct gpio_desc    *reset_gpio;//复位
	struct gpio_desc    *pwdn_gpio;//
	struct gpio_desc    *power_gpio;
	struct regulator_bulk_data supplies[GC2053_NUM_SUPPLIES];//电源供应数组，用于管理传感器的多个电源

	struct pinctrl      	*pinctrl;
	struct pinctrl_state    *pins_default;
	struct pinctrl_state    *pins_sleep;

	struct v4l2_subdev  subdev;
	struct media_pad    pad;
	//这些字段用于管理V4L2控件，包括曝光时间、模拟增益、水平和垂直空白、水平和垂直翻转等。
	struct v4l2_ctrl_handler ctrl_handler;
	struct v4l2_ctrl    *exposure;
	struct v4l2_ctrl    *anal_gain;
	struct v4l2_ctrl    *hblank;
	struct v4l2_ctrl    *vblank;
	struct v4l2_ctrl    *h_flip;
	struct v4l2_ctrl    *v_flip;
	//同步对传感器的访问和存储传感器的当前状态，如是否正在流式传输数据和电源是否开启。
	struct mutex        mutex;
	bool            streaming;
	bool			power_on;
	//用于存储当前的传感器模式、数据通道数量、配置编号和像素速率。
	const struct gc2053_mode *cur_mode;
	unsigned int        lane_num;
	unsigned int        cfg_num;
	unsigned int        pixel_rate;
//传感器的索引、朝向、名称和镜头名称。
	u32         module_index;
	const char      *module_facing;
	const char      *module_name;
	const char      *len_name;
	//自动白平衡（AWB）和镜头校正（LSC）的配置，以及传感器的翻转设置。
	struct rkmodule_awb_cfg awb_cfg;
	struct rkmodule_lsc_cfg lsc_cfg;
	u8			flip;
};

/*
 * window_size=1920*1080 mipi@2lane
 * mclk=24mhz,mipi_clk=594Mbps
 * pixel_line_total=2200,line_frame_total=1125
 * row_time=29.629us,frame_rate=30fps
 */
static const struct regval gc2053_1920x1080_regs_2lane[] = {
	/****system****/
	{0xfe, 0x80},
	{0xfe, 0x80},
	{0xfe, 0x80},
	{0xfe, 0x00},
	{0xf2, 0x00},
	{0xf3, 0x00},
	{0xf4, 0x36},
	{0xf5, 0xc0},
	{0xf6, 0x44},
	{0xf7, 0x01},
	{0xf8, 0x63},
	{0xf9, 0x40},
	{0xfc, 0x8e},
	/****CISCTL & ANALOG****/
	{0xfe, 0x00},
	{0x87, 0x18},
	{0xee, 0x30},
	{0xd0, 0xb7},
	{0x03, 0x04},
	{0x04, 0x60},
	{0x05, 0x04},
	{0x06, 0x4c},
	{0x07, 0x00},
	{0x08, 0x11},
	{0x09, 0x00},
	{0x0a, 0x02},
	{0x0b, 0x00},
	{0x0c, 0x02},
	{0x0d, 0x04},
	{0x0e, 0x40},
	{0x12, 0xe2},
	{0x13, 0x16},
	{0x19, 0x0a},
	{0x21, 0x1c},
	{0x28, 0x0a},
	{0x29, 0x24},
	{0x2b, 0x04},
	{0x32, 0xf8},
	{0x37, 0x03},
	{0x39, 0x15},
	{0x43, 0x07},
	{0x44, 0x40},
	{0x46, 0x0b},
	{0x4b, 0x20},
	{0x4e, 0x08},
	{0x55, 0x20},
	{0x66, 0x05},
	{0x67, 0x05},
	{0x77, 0x01},
	{0x78, 0x00},
	{0x7c, 0x93},
	{0x8c, 0x12},
	{0x8d, 0x92},
	{0x90, 0x00},
	{0x9d, 0x10},
	{0xce, 0x7c},
	{0xd2, 0x41},
	{0xd3, 0xdc},
	{0xe6, 0x50},
	/*gain*/
	{0xb6, 0xc0},
	{0xb0, 0x60},
	{0xb1, 0x01},
	{0xb2, 0x00},
	{0xb3, 0x00},
	{0xb4, 0x00},
	{0xb8, 0x01},
	{0xb9, 0x00},
	/*blk*/
	{0x26, 0x30},
	{0xfe, 0x01},
	{0x40, 0x23},
	{0x55, 0x07},
	{0x60, 0x40},
	{0xfe, 0x04},
	{0x14, 0x78},
	{0x15, 0x78},
	{0x16, 0x78},
	{0x17, 0x78},
	/*window*/
	{0xfe, 0x01},
	{0x92, 0x02},
	{0x94, 0x02},
	{0x95, 0x04},
	{0x96, 0x38},
	{0x97, 0x07},
	{0x98, 0x80},
	/*ISP*/
	{0xfe, 0x01},
	{0x01, 0x05},
	{0x02, 0x89},
	{0x04, 0x01},
	{0x07, 0xa6},
	{0x08, 0xa9},
	{0x09, 0xa8},
	{0x0a, 0xa7},
	{0x0b, 0xff},
	{0x0c, 0xff},
	{0x0f, 0x00},
	{0x50, 0x1c},
	{0x89, 0x03},
	{0xfe, 0x04},
	{0x28, 0x86},
	{0x29, 0x86},
	{0x2a, 0x86},
	{0x2b, 0x68},
	{0x2c, 0x68},
	{0x2d, 0x68},
	{0x2e, 0x68},
	{0x2f, 0x68},
	{0x30, 0x4f},
	{0x31, 0x68},
	{0x32, 0x67},
	{0x33, 0x66},
	{0x34, 0x66},
	{0x35, 0x66},
	{0x36, 0x66},
	{0x37, 0x66},
	{0x38, 0x62},
	{0x39, 0x62},
	{0x3a, 0x62},
	{0x3b, 0x62},
	{0x3c, 0x62},
	{0x3d, 0x62},
	{0x3e, 0x62},
	{0x3f, 0x62},
	/****DVP & MIPI****/
	{0xfe, 0x01},
	{0x9a, 0x06},
	{0xfe, 0x00},
	{0x7b, 0x2a},
	{0x23, 0x2d},
	{0xfe, 0x03},
	{0x01, 0x27},
	{0x02, 0x5f},
	{0x03, 0xb6},
	{0x12, 0x80},
	{0x13, 0x07},
	{0x15, 0x12},
	{0xfe, 0x00},
	{0x3e, 0x91},
	{REG_NULL, 0x00},
};

static const struct gc2053_mode supported_modes[] = {
	/*.width 和 .height：分别定义了模式的宽度和高度，单位是像素。在这个例子中，模式是1920x1080，即常见的1080p分辨率。

.max_fps：定义了模式下的最大帧率（frames per second）。numerator 和 denominator 构成了帧率的分数表示，例如这里的 10000/300000 可以简化为 1/30，表示最大帧率是30fps。

.exp_def、.hts_def 和 .vts_def：这些字段定义了曝光时间（exposure time）、水平同步时间（horizontal total size）和垂直同步时间（vertical total size）的默认值。这些值通常是寄存器设置的一部分，用于配置传感器的特定操作模式。

.reg_list：指向一个包含寄存器设置列表的指针，这个列表包含了设置传感器为当前模式所需的所有寄存器值。

.hdr_mode：定义了高动态范围（High Dynamic Range, HDR）模式的状态。在这个例子中，NO_HDR 表示该模式不支持HDR。

.vc[PAD0]：定义了第一个数据通道（PAD0）的配置。V4L2_MBUS_CSI2_CHANNEL_0 表示使用的是MIPI CSI-2接口的通道0。*/
	{
		.width = 1920,
		.height = 1080,
		.max_fps = {
			.numerator = 10000,
			.denominator = 300000,
		},
		.exp_def = 0x460,
		.hts_def = 0x898,
		.vts_def = 0x465,
		.reg_list = gc2053_1920x1080_regs_2lane,
		.hdr_mode = NO_HDR,
		.vc[PAD0] = V4L2_MBUS_CSI2_CHANNEL_0,
	},
};

static const s64 link_freq_menu_items[] = {
	MIPI_FREQ_297M
};

/*gc2053_write_reg 函数通过I2C通信向传感器设备写入一个寄存器值。
这个函数是驱动程序与硬件设备交互的基本操作之一，用于配置传感器的行为或状态。*/
/* sensor register write */
static int gc2053_write_reg(struct i2c_client *client, u8 reg, u8 val)
{
	/*声明了一个 i2c_msg 结构体用于存储I2C消息，一个8位无符号整数数组 buf 用于存储要发送的数据（寄存器地址和值），
	以及一个整型变量 ret 用于存储操作的返回状态。*/
	struct i2c_msg msg;
	u8 buf[2];
	int ret;

	/*将寄存器地址和要写入的值分别存储在 buf 数组的第一个和第二个元素中。
	这里使用位运算 & 0xFF 确保 reg 值在8位范围内，防止高位数据被误写入。*/
	buf[0] = reg & 0xFF;
	buf[1] = val;

	/*设置I2C消息的地址为传感器设备的地址，消息标志为客户端的标志，消息缓冲区为 buf 数组，消息长度为数组大小。*/
	msg.addr = client->addr;
	msg.flags = client->flags;
	msg.buf = buf;
	msg.len = sizeof(buf);

	/*调用 i2c_transfer 函数执行I2C数据传输。这个函数接受I2C适配器、指向I2C消息的指针以及消息数量作为参数。
	如果传输成功，i2c_transfer 将返回0，否则返回一个错误码。*/
	ret = i2c_transfer(client->adapter, &msg, 1);
	if (ret >= 0)
		return 0;

	dev_err(&client->dev,
		"gc2053 write reg(0x%x val:0x%x) failed !\n", reg, val);

	return ret;
}

/*，其目的是将一系列寄存器值写入连接到I2C总线上的传感器设备（如gc2053）。
这个函数通常在初始化设备或配置设备以进入特定工作模式时被调用。*/
/*client 是一个指向 i2c_client 结构体的指针，代表I2C通信的客户端（即传感器设备）；
regs 是一个指向 regval 结构体数组的指针，每个 regval 结构体包含一个寄存器地址和相应的值。*/
static int gc2053_write_array(struct i2c_client *client,
				  const struct regval *regs)
{
	/*
	声明一个整型变量 i 用于循环索引，和一个整型变量 ret 用于存储函数的返回状态。初始时，ret 被设置为0，表示没有错误。
	*/
	int i, ret = 0;

	i = 0;
	/*从数组的第一个元素开始，循环继续直到遇到一个地址为 REG_NULL 的 regval 结构体，这通常用作数组结束的标识。*/
	while (regs[i].addr != REG_NULL) {
		/*对于数组中的每个 regval 结构体，调用 gc2053_write_reg 函数将寄存器地址和值写入传感器。
		gc2053_write_reg 函数的返回值被存储在 ret 变量中。*/
		ret = gc2053_write_reg(client, regs[i].addr, regs[i].val);
		if (ret) {
			dev_err(&client->dev, "%s failed !\n", __func__);
			break;
		}
		i++;//如果当前寄存器值写入成功，循环将继续到下一个寄存器值。
	}
/*gc2053_write_array 函数通过遍历一个包含寄存器地址和值的数组，并将这些值依次写入传感器，实现了对传感器的配置*/
	return ret;
}

/* sensor register read */
/*它用于从连接到I2C总线上的传感器设备（如gc2053）读取一个寄存器的值
client 是一个指向 i2c_client 结构体的指针，代表I2C通信的客户端（即传感器设备）；
reg 是一个无符号8位整数，表示要读取的寄存器地址；val 是一个指向无符号8位整数的指针，用于存储读取到的寄存器值。*/
static int gc2053_read_reg(struct i2c_client *client, u8 reg, u8 *val)
{
	/*准备I2C消息和数据：
	声明了一个 i2c_msg 结构体数组 msg 用于存储I2C消息，一个8位无符号整数数组
	 buf 用于临时存储发送的寄存器地址和接收到的寄存器值，以及一个整型变量 ret 用于存储操作的返回状态。*/
	struct i2c_msg msg[2];
	u8 buf[1];
	int ret;
/*准备寄存器地址消息：将寄存器地址 reg 存储在 buf 数组的第一个元素中，同时使用位运算 & 0xFF 确保地址值在8位范围内。*/
	buf[0] = reg & 0xFF;
/*配置I2C消息：第一个消息 msg[0] 用于发送寄存器地址，
第二个消息 msg[1] 用于接收寄存器的值。I2C_M_RD 标志表示这是一个读操作。*/
	msg[0].addr = client->addr;
	msg[0].flags = client->flags;
	msg[0].buf = buf;
	msg[0].len = sizeof(buf);

	msg[1].addr = client->addr;
	msg[1].flags = client->flags | I2C_M_RD;
	msg[1].buf = buf;
	msg[1].len = 1;
/*执行I2C传输：调用 i2c_transfer 函数执行I2C数据传输。这个函数接受I2C适配器、
指向I2C消息数组的指针以及消息数量作为参数。如果传输成功，i2c_transfer 将返回0，否则返回一个错误码。*/
	ret = i2c_transfer(client->adapter, msg, 2);
	if (ret >= 0) {//读取寄存器值并处理结果：如果传输成功，则将接收到的寄存器值存储在 val 指向的位置，并返回0表示成功。
		*val = buf[0];
		return 0;
	}

	dev_err(&client->dev,
		"gc2053 read reg(0x%x val:0x%x) failed !\n", reg, *val);

	return ret;
}

static int gc2053_get_reso_dist(const struct gc2053_mode *mode,
				struct v4l2_mbus_framefmt *framefmt)
{
	return abs(mode->width - framefmt->width) +
		   abs(mode->height - framefmt->height);
}

static const struct gc2053_mode *
gc2053_find_best_fit(struct gc2053 *gc2053, struct v4l2_subdev_format *fmt)
{
	struct v4l2_mbus_framefmt *framefmt = &fmt->format;
	int dist;
	int cur_best_fit = 0;
	int cur_best_fit_dist = -1;
	unsigned int i;

	for (i = 0; i < gc2053->cfg_num; i++) {
		dist = gc2053_get_reso_dist(&supported_modes[i], framefmt);
		if (cur_best_fit_dist == -1 || dist <= cur_best_fit_dist) {
			cur_best_fit_dist = dist;
			cur_best_fit = i;
		}
	}

	return &supported_modes[cur_best_fit];
}

static uint8_t gain_reg_table[29][4] = {
	{0x00, 0x00, 0x01, 0x00},
	{0x00, 0x10, 0x01, 0x0c},
	{0x00, 0x20, 0x01, 0x1b},
	{0x00, 0x30, 0x01, 0x2c},
	{0x00, 0x40, 0x01, 0x3f},
	{0x00, 0x50, 0x02, 0x16},
	{0x00, 0x60, 0x02, 0x35},
	{0x00, 0x70, 0x03, 0x16},
	{0x00, 0x80, 0x04, 0x02},
	{0x00, 0x90, 0x04, 0x31},
	{0x00, 0xa0, 0x05, 0x32},
	{0x00, 0xb0, 0x06, 0x35},
	{0x00, 0xc0, 0x08, 0x04},
	{0x00, 0x5a, 0x09, 0x19},
	{0x00, 0x83, 0x0b, 0x0f},
	{0x00, 0x93, 0x0d, 0x12},
	{0x00, 0x84, 0x10, 0x00},
	{0x00, 0x94, 0x12, 0x3a},
	{0x01, 0x2c, 0x1a, 0x02},
	{0x01, 0x3c, 0x1b, 0x20},
	{0x00, 0x8c, 0x20, 0x0f},
	{0x00, 0x9c, 0x26, 0x07},
	{0x02, 0x64, 0x36, 0x21},
	{0x02, 0x74, 0x37, 0x3a},
	{0x00, 0xc6, 0x3d, 0x02},
	{0x00, 0xdc, 0x3f, 0x3f},
	{0x02, 0x85, 0x3f, 0x3f},
	{0x02, 0x95, 0x3f, 0x3f},
	{0x00, 0xce, 0x3f, 0x3f},
};

static  uint32_t gain_level_table[30] = {
	64,
	76,
	91,
	108,
	127,
	150,
	181,
	214,
	258,
	305,
	370,
	437,
	516,
	601,
	719,
	850,
	1024,
	1210,
	1538,
	1760,
	2063,
	2439,
	2881,
	3393,
	3970,
	4737,
	5572,
	6552,
	7713,
	0xffffffff
};

static int gc2053_set_gain(struct gc2053 *gc2053, u32 gain)
{
	int ret;
	uint8_t i = 0;
	uint8_t total = 0;
	uint8_t temp = 0;

	total = sizeof(gain_level_table) / sizeof(u32) - 1;
	for (i = 0; i < total; i++) {
		if ((gain_level_table[i] <= gain) && (gain < gain_level_table[i+1]))
			break;
	}

	ret = gc2053_write_reg(gc2053->client, 0xb4, gain_reg_table[i][0]);
	ret |= gc2053_write_reg(gc2053->client, 0xb3, gain_reg_table[i][1]);
	ret |= gc2053_write_reg(gc2053->client, 0xb8, gain_reg_table[i][2]);
	ret |= gc2053_write_reg(gc2053->client, 0xb9, gain_reg_table[i][3]);

	temp = 64 * gain / gain_level_table[i];
	ret |= gc2053_write_reg(gc2053->client, 0xb1, (temp >> 6));
	ret |= gc2053_write_reg(gc2053->client, 0xb2, (temp << 2) & 0xfc);

	return ret;
}
/*用于处理对 gc2053 摄像头传感器的V4L2控件的修改请求。
当用户空间的应用程序通过V4L2 API改变控件的值时，这个函数会被调用以更新传感器的相应设置。*/
static int gc2053_set_ctrl(struct v4l2_ctrl *ctrl)
{
	/*使用 container_of 宏从控件的处理器指针获取 gc2053 设备结构体，然后获取与之关联的I2C客户端*/
	struct gc2053 *gc2053 = container_of(ctrl->handler,
						 struct gc2053, ctrl_handler);
	struct i2c_client *client = gc2053->client;
	/*初始化一些变量，包括一个用于存储最大值的 s64 类型变量 max，一个整型变量 ret 用于存储函数的返回状态，
	以及一个无符号32位整数 vts 用于存储VTS（垂直时间设置）值。*/
	s64 max;
	int ret = 0;
	u32 vts = 0;

	/* Propagate change of current control to all related controls */
	switch (ctrl->id) {//使用 switch 语句根据控件的ID来执行不同的设置操作。
	case V4L2_CID_VBLANK:
		/* Update max exposure while meeting expected vblanking */
		max = gc2053->cur_mode->height + ctrl->val - 4;
		__v4l2_ctrl_modify_range(gc2053->exposure,
					 gc2053->exposure->minimum, max,
					 gc2053->exposure->step,
					 gc2053->exposure->default_value);
		break;
	}
/*使用 pm_runtime_get_if_in_use 和 pm_runtime_put 函数管理设备的电源运行时状态。
这有助于在设备活跃时保持电源开启，不活跃时关闭电源以节省电能*/
	if (!pm_runtime_get_if_in_use(&client->dev))
		return 0;

	switch (ctrl->id) {
	case V4L2_CID_EXPOSURE://当设置曝光时间控件时，写入曝光时间的高字节和低字节到传感器的相应寄存器。
		ret = gc2053_write_reg(gc2053->client, GC2053_REG_EXP_H,
					   (ctrl->val >> 8) & 0x3f);
		ret |= gc2053_write_reg(gc2053->client, GC2053_REG_EXP_L,
					   ctrl->val & 0xff);
		break;
	case V4L2_CID_ANALOGUE_GAIN://当设置模拟增益控件时，调用 gc2053_set_gain 函数来更新传感器的增益设置。
		gc2053_set_gain(gc2053, ctrl->val);
		break;
	case V4L2_CID_VBLANK://处理垂直空白（VBLANK）控件：更新最大曝光时间，以确保满足预期的垂直空白时间。
		vts = ctrl->val + gc2053->cur_mode->height;
		ret = gc2053_write_reg(gc2053->client, GC2053_REG_VTS_H, (vts >> 8) & 0x3f);
		ret |= gc2053_write_reg(gc2053->client, GC2053_REG_VTS_L, vts & 0xff);
		break;
	case V4L2_CID_HFLIP://当设置水平或垂直翻转控件时，更新 gc2053 设备的翻转标志，并写入相应的寄存器。
		if (ctrl->val)
			gc2053->flip |= GC_MIRROR_BIT_MASK;
		else
			gc2053->flip &= ~GC_MIRROR_BIT_MASK;
		break;
	case V4L2_CID_VFLIP:
		if (ctrl->val)
			gc2053->flip |= GC_FLIP_BIT_MASK;
		else
			gc2053->flip &= ~GC_FLIP_BIT_MASK;
		break;
	default:
		dev_warn(&client->dev, "%s Unhandled id:0x%x, val:0x%x\n",
			 __func__, ctrl->id, ctrl->val);
		break;
	}

	pm_runtime_put(&client->dev);
	return ret;
}

static const struct v4l2_ctrl_ops gc2053_ctrl_ops = {
	.s_ctrl = gc2053_set_ctrl,
};

static int gc2053_configure_regulators(struct gc2053 *gc2053)
{
	unsigned int i;

	for (i = 0; i < GC2053_NUM_SUPPLIES; i++)
		gc2053->supplies[i].supply = gc2053_supply_names[i];

	return devm_regulator_bulk_get(&gc2053->client->dev,
					   GC2053_NUM_SUPPLIES,
					   gc2053->supplies);
}

static int gc2053_parse_of(struct gc2053 *gc2053)
{
	struct device *dev = &gc2053->client->dev;
	struct device_node *endpoint;
	struct fwnode_handle *fwnode;
	int rval;

	endpoint = of_graph_get_next_endpoint(dev->of_node, NULL);
	if (!endpoint) {
		dev_err(dev, "Failed to get endpoint\n");
		return -EINVAL;
	}
	fwnode = of_fwnode_handle(endpoint);
	rval = fwnode_property_read_u32_array(fwnode, "data-lanes", NULL, 0);
	if (rval <= 0) {
		dev_warn(dev, " Get mipi lane num failed!\n");
		return -1;
	}

	gc2053->lane_num = rval;
	if (2 == gc2053->lane_num) {
		gc2053->cur_mode = &supported_modes[0];
		gc2053->cfg_num = ARRAY_SIZE(supported_modes);

		/*pixel rate = link frequency * 2 * lanes / BITS_PER_SAMPLE */
		gc2053->pixel_rate = MIPI_FREQ_297M * 2U * (gc2053->lane_num) / 10U;
		dev_info(dev, "lane_num(%d)  pixel_rate(%u)\n",
				 gc2053->lane_num, gc2053->pixel_rate);
	} else {
		dev_info(dev, "gc2053 can not support the lane num(%d)\n", gc2053->lane_num);
	}
	return 0;
}

/*它用于初始化 gc2053 摄像头传感器的V4L2控件。
V4L2控件允许用户空间的应用程序通过V4L2 API控制系统的各种参数，如曝光时间、增益、翻转等*/
static int gc2053_initialize_controls(struct gc2053 *gc2053)
{
	const struct gc2053_mode *mode;
	struct v4l2_ctrl_handler *handler;
	struct v4l2_ctrl *ctrl;
	s64 exposure_max, vblank_def;
	u32 h_blank;
	int ret;

	handler = &gc2053->ctrl_handler;//获取 gc2053 设备的控件处理器，并准备初始化
	mode = gc2053->cur_mode;
	ret = v4l2_ctrl_handler_init(handler, 8);//调用 v4l2_ctrl_handler_init 函数初始化控件处理器，8 表示最多可以注册8个控件。
	if (ret)
		return ret;
	handler->lock = &gc2053->mutex;
/*使用 v4l2_ctrl_new_int_menu 和 v4l2_ctrl_new_std 函数创建不同类型的控件，
如菜单选择控件、标准控件等，并注册到控件处理器中。控件的类型和参数根据传感器的特性和需求进行设置。*/
	ctrl = v4l2_ctrl_new_int_menu(handler, NULL, V4L2_CID_LINK_FREQ,
					  0, 0, link_freq_menu_items);
	if (ctrl)
		ctrl->flags |= V4L2_CTRL_FLAG_READ_ONLY;

	v4l2_ctrl_new_std(handler, NULL, V4L2_CID_PIXEL_RATE,
			  0, gc2053->pixel_rate, 1, gc2053->pixel_rate);

	h_blank = mode->hts_def - mode->width;
	gc2053->hblank = v4l2_ctrl_new_std(handler, NULL, V4L2_CID_HBLANK,
				h_blank, h_blank, 1, h_blank);
/*对于某些控件，如水平空白时间（hblank），设置为只读，这意味着用户空间的应用程序不能修改这些控件的值。*/
	if (gc2053->hblank)
		gc2053->hblank->flags |= V4L2_CTRL_FLAG_READ_ONLY;

	vblank_def = mode->vts_def - mode->height;
	gc2053->vblank = v4l2_ctrl_new_std(handler, &gc2053_ctrl_ops,
				V4L2_CID_VBLANK, vblank_def,
				GC2053_VTS_MAX - mode->height,
				1, vblank_def);

	exposure_max = mode->vts_def - 4;
	gc2053->exposure = v4l2_ctrl_new_std(handler, &gc2053_ctrl_ops,
				V4L2_CID_EXPOSURE, GC2053_EXPOSURE_MIN,
				exposure_max, GC2053_EXPOSURE_STEP,
				mode->exp_def);

	gc2053->anal_gain = v4l2_ctrl_new_std(handler, &gc2053_ctrl_ops,
				V4L2_CID_ANALOGUE_GAIN, GC2053_GAIN_MIN,
				GC2053_GAIN_MAX, GC2053_GAIN_STEP,
				GC2053_GAIN_DEFAULT);

	gc2053->h_flip = v4l2_ctrl_new_std(handler, &gc2053_ctrl_ops,
				V4L2_CID_HFLIP, 0, 1, 1, 0);

	gc2053->v_flip = v4l2_ctrl_new_std(handler, &gc2053_ctrl_ops,
				V4L2_CID_VFLIP, 0, 1, 1, 0);
	gc2053->flip = 0;

	if (handler->error) {
		ret = handler->error;
		dev_err(&gc2053->client->dev,
			"Failed to init controls(%d)\n", ret);
		goto err_free_handler;
	}

	gc2053->subdev.ctrl_handler = handler;//将初始化好的控件处理器关联到 gc2053 子设备上。
	return 0;

err_free_handler:
	v4l2_ctrl_handler_free(handler);
	return ret;
}

/* Calculate the delay in us by clock rate and clock cycles */
static inline u32 gc2053_cal_delay(u32 cycles)
{
	return DIV_ROUND_UP(cycles, GC2053_XVCLK_FREQ / 1000 / 1000);
}

/*它用于开启 gc2053 摄像头传感器的电源。
这个函数执行一系列操作来确保传感器正确地从电源关闭状态转换到电源开启状态，为后续的数据传输和图像捕获做准备。*/
static int __gc2053_power_on(struct gc2053 *gc2053)
{
	int ret;
	u32 delay_us;
	struct device *dev = &gc2053->client->dev;//获取与 gc2053 设备关联的设备结构体，用于后续的错误和警告日志输出。

/*如果 gc2053 设备的引脚控制器和默认引脚配置不为错误或空，尝试应用默认引脚配置。如果设置失败，记录错误信息。*/
	if (!IS_ERR_OR_NULL(gc2053->pins_default)) {
		ret = pinctrl_select_state(gc2053->pinctrl,
					   gc2053->pins_default);
		if (ret < 0)
			dev_err(dev, "could not set pins\n");
	}
/*尝试设置摄像头传感器的XVCLK时钟频率，并准备并启用时钟。如果时钟设置或启用失败，记录错误信息并返回错误码。*/
	ret = clk_set_rate(gc2053->xvclk, GC2053_XVCLK_FREQ);
	if (ret < 0)
		dev_warn(dev, "Failed to set xvclk rate (24MHz)\n");
	if (clk_get_rate(gc2053->xvclk) != GC2053_XVCLK_FREQ)
		dev_warn(dev, "xvclk mismatched, modes are based on 24MHz\n");
	ret = clk_prepare_enable(gc2053->xvclk);
	if (ret < 0) {
		dev_err(dev, "Failed to enable xvclk\n");
		return ret;
	}
/*尝试启用所有为 gc2053 设备定义的电源供应。如果电源供应无法启用，记录错误信息并跳转到关闭时钟的标签。*/	
	ret = regulator_bulk_enable(GC2053_NUM_SUPPLIES, gc2053->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators\n");
		goto disable_clk;
	}
	/*如果 gc2053 设备的电源和复位GPIO不为错误，设置它们的值以开启电源和复位传感器*/
	if (!IS_ERR(gc2053->power_gpio)) {
		gpiod_set_value_cansleep(gc2053->power_gpio, 1);
		usleep_range(100, 200);
	}
	if (!IS_ERR(gc2053->reset_gpio)) {
		gpiod_set_value_cansleep(gc2053->reset_gpio, 1);
		usleep_range(100, 200);
	}
	/*如果 gc2053 设备的功率下拉GPIO不为错误，设置其值为低电平，确保传感器处于关闭状态。*/
	if (!IS_ERR(gc2053->pwdn_gpio))
		gpiod_set_value_cansleep(gc2053->pwdn_gpio, 0);

	if (!IS_ERR(gc2053->reset_gpio))//等待一段特定的时间，确保传感器完成复位
		gpiod_set_value_cansleep(gc2053->reset_gpio, 0);
	usleep_range(3000, 6000);
	/* 8192 cycles prior to first SCCB transaction */
	delay_us = gc2053_cal_delay(8192);//计算在进行第一个SCCB（串行相机控制总线）事务之前的校准延迟，并等待这段延迟时间。
	usleep_range(delay_us, delay_us * 2);
	return 0;
/*__gc2053_power_on 函数通过设置引脚配置、时钟和GPIO，以及等待传感器准备就绪，
来确保 gc2053 摄像头传感器的电源被正确开启。这个函数是传感器驱动程序中的关键部分，确保传感器能够正确地进入工作状态。*/
disable_clk:
	clk_disable_unprepare(gc2053->xvclk);
	return ret;
}

static void __gc2053_power_off(struct gc2053 *gc2053)
{
	int ret;
	struct device *dev = &gc2053->client->dev;

	if (!IS_ERR(gc2053->pwdn_gpio))
		gpiod_set_value_cansleep(gc2053->pwdn_gpio, 1);
	clk_disable_unprepare(gc2053->xvclk);

	if (!IS_ERR(gc2053->reset_gpio))
		gpiod_set_value_cansleep(gc2053->reset_gpio, 1);

	if (!IS_ERR_OR_NULL(gc2053->pins_sleep)) {
		ret = pinctrl_select_state(gc2053->pinctrl,
					   gc2053->pins_sleep);
		if (ret < 0)
			dev_dbg(dev, "could not set pins\n");
	}
	if (!IS_ERR(gc2053->power_gpio))
		gpiod_set_value_cansleep(gc2053->power_gpio, 0);
	regulator_bulk_disable(GC2053_NUM_SUPPLIES, gc2053->supplies);
}
/*这个函数通过读取传感器的芯片ID寄存器来检查传感器是否为预期的型号。
gc2053 是一个指向 gc2053 设备特定结构体的指针；client 是一个指向 i2c_client 结构体的指针，
代表I2C通信的客户端（即摄像头传感器设备）。*/
static int gc2053_check_sensor_id(struct gc2053 *gc2053,
				   struct i2c_client *client)
{
	struct device *dev = &gc2053->client->dev;
	u8 pid = 0, ver = 0;
	u16 id = 0;
	int ret = 0;

	/* Check sensor revision */
	/*使用 gc2053_read_reg 函数读取传感器的产品ID高字节（pid）和版本号（ver）。如果读取失败，ret 将包含错误码。*/
	ret = gc2053_read_reg(client, GC2053_REG_CHIP_ID_H, &pid);
	ret |= gc2053_read_reg(client, GC2053_REG_CHIP_ID_L, &ver);
	if (ret) {
		dev_err(&client->dev, "gc2053_read_reg failed (%d)\n", ret);
		return ret;
	}
/*使用读取到的 pid 和 ver 组合成传感器ID，
并与预期的 GC2053_CHIP_ID 进行比较。如果ID不匹配，记录错误信息并返回 -ENODEV，表示没有检测到设备。*/
	id = SENSOR_ID(pid, ver);
	if (id != GC2053_CHIP_ID) {
		dev_err(&client->dev,
				"Sensor detection failed (%04X,%d)\n",
				id, ret);
		return -ENODEV;
	}

	dev_info(dev, "Detected GC%04x sensor\n", id);//如果传感器ID匹配，记录一条信息日志，表示已成功检测到 gc2053 传感器。
	return 0;
}

/*它用于设置 gc2053 摄像头传感器的图像翻转和镜像模式。
这个函数允许用户或应用程序改变图像的方向，例如，翻转图像或创建镜像效果。
gc2053 是一个指向 gc2053 设备特定结构体的指针；mode 是一个无符号8位整数，表示要设置的翻转和镜像模式。*/
static int gc2053_set_flip(struct gc2053 *gc2053, u8 mode)
{
	u8 match_reg = 0;
	/*读取当前翻转和镜像寄存器的值：调用 gc2053_read_reg 函数读取传感器的翻转和镜像控制寄存器
	（GC2053_FLIP_MIRROR_REG）的当前值，并将其存储在 match_reg 变量中。*/
	gc2053_read_reg(gc2053->client, GC2053_FLIP_MIRROR_REG, &match_reg);
	//根据传入的模式设置翻转和镜像位：
	if (mode == GC_FLIP_BIT_MASK) {//如果传入的 mode 是 GC_FLIP_BIT_MASK，则设置翻转位，清除镜像位。
		match_reg |= GC_FLIP_BIT_MASK;
		match_reg &= ~GC_MIRROR_BIT_MASK;
	} else if (mode == GC_MIRROR_BIT_MASK) {//如果传入的 mode 是 GC_MIRROR_BIT_MASK，则设置镜像位，清除翻转位。
		match_reg |= GC_MIRROR_BIT_MASK;
		match_reg &= ~GC_FLIP_BIT_MASK;
	} else if (mode == (GC_MIRROR_BIT_MASK |//如果传入的 mode 是翻转和镜像位的组合，则同时设置这两个位。
		GC_FLIP_BIT_MASK)) {
		match_reg |= GC_FLIP_BIT_MASK;
		match_reg |= GC_MIRROR_BIT_MASK;
	} else {//对于其他任何模式，清除翻转和镜像位，这意味着不应用任何翻转或镜像。
		match_reg &= ~GC_FLIP_BIT_MASK;
		match_reg &= ~GC_MIRROR_BIT_MASK;
	}
	/*写入新的翻转和镜像设置到传感器：调用 gc2053_write_reg 函数将修改后的 match_reg 值写回传感器的翻转和镜像控制寄存器。
	函数返回写入操作的状态，如果成功则为0，失败则为错误码*/
	return gc2053_write_reg(gc2053->client, GC2053_FLIP_MIRROR_REG, match_reg);
}

/*它是用于启动 gc2053 摄像头传感器的视频流的内部函数。
这个函数在 gc2053 子设备的驱动程序中被调用，以执行启动视频流所需的一系列操作。*/
static int __gc2053_start_stream(struct gc2053 *gc2053)
{
	int ret;
/*调用 gc2053_write_array 函数，将当前模式（gc2053->cur_mode）的寄存器设置列表（reg_list）写入传感器。
这是为了配置传感器以准备开始视频流。如果写入操作失败，函数将返回错误码。*/
	ret = gc2053_write_array(gc2053->client, gc2053->cur_mode->reg_list);
	if (ret)
		return ret;

	/* In case these controls are set before streaming */
	mutex_unlock(&gc2053->mutex);
	/*调用 v4l2_ctrl_handler_setup 函数来设置控件处理器（gc2053->ctrl_handler）。
	这通常是为了确保所有的V4L2控件都已正确初始化，并且可以响应用户空间的请求。如果设置失败，函数将返回错误码。*/
	ret = v4l2_ctrl_handler_setup(&gc2053->ctrl_handler);
	mutex_lock(&gc2053->mutex);
	/*调用 gc2053_set_flip 函数来设置传感器的翻转模式（gc2053->flip）。
	这是为了确保视频流的输出方向正确。如果设置失败，函数将返回错误码。*/
	ret = gc2053_set_flip(gc2053, gc2053->flip);
	if (ret)
		return ret;
		/*向传感器写入一个命令，以开始视频流。这个命令将传感器的控制模式寄存器（GC2053_REG_CTRL_MODE）
		设置为流模式（GC2053_MODE_STREAMING）。
		如果命令成功执行，函数将返回0，表示视频流已成功启动。*/
	return gc2053_write_reg(gc2053->client, GC2053_REG_CTRL_MODE,
							GC2053_MODE_STREAMING);
	/*gc2053_set_flip 函数通过读取当前的翻转和镜像设置，根据传入的模式进行修改，
	然后将新的设置写回传感器，从而实现对图像翻转和镜像效果的控制*/						
}

static int __gc2053_stop_stream(struct gc2053 *gc2053)
{
	return gc2053_write_reg(gc2053->client, GC2053_REG_CTRL_MODE,
							GC2053_MODE_SW_STANDBY);
}

static void gc2053_get_module_inf(struct gc2053 *gc2053,
				  struct rkmodule_inf *inf)
{
	memset(inf, 0, sizeof(*inf));
	strlcpy(inf->base.sensor, GC2053_NAME, sizeof(inf->base.sensor));
	strlcpy(inf->base.module, gc2053->module_name,
		sizeof(inf->base.module));
	strlcpy(inf->base.lens, gc2053->len_name, sizeof(inf->base.lens));
}

static void gc2053_set_awb_cfg(struct gc2053 *gc2053,
				   struct rkmodule_awb_cfg *cfg)
{
	mutex_lock(&gc2053->mutex);
	memcpy(&gc2053->awb_cfg, cfg, sizeof(*cfg));
	mutex_unlock(&gc2053->mutex);
}

static void gc2053_set_lsc_cfg(struct gc2053 *gc2053,
				   struct rkmodule_lsc_cfg *cfg)
{
	mutex_lock(&gc2053->mutex);
	memcpy(&gc2053->lsc_cfg, cfg, sizeof(*cfg));
	mutex_unlock(&gc2053->mutex);
}

static long gc2053_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
	struct gc2053 *gc2053 = to_gc2053(sd);
	long ret = 0;
	struct rkmodule_hdr_cfg *hdr_cfg;
	u32 stream = 0;

	switch (cmd) {
	case RKMODULE_GET_HDR_CFG://RKMODULE_GET_HDR_CFG：获取高动态范围（HDR）配置。
		hdr_cfg = (struct rkmodule_hdr_cfg *)arg;
		hdr_cfg->esp.mode = HDR_NORMAL_VC;
		hdr_cfg->hdr_mode = gc2053->cur_mode->hdr_mode;
		break;
	case RKMODULE_SET_HDR_CFG:
	case RKMODULE_SET_CONVERSION_GAIN://设置HDR配置和转换增益
		break;
	case RKMODULE_GET_MODULE_INFO://获取模块信息
		gc2053_get_module_inf(gc2053, (struct rkmodule_inf *)arg);
		break;
	case RKMODULE_AWB_CFG://设置自动白平衡（AWB）配置。
		gc2053_set_awb_cfg(gc2053, (struct rkmodule_awb_cfg *)arg);
		break;
	case RKMODULE_LSC_CFG://设置镜头校正（LSC）配置。
		gc2053_set_lsc_cfg(gc2053, (struct rkmodule_lsc_cfg *)arg);
		break;
	case RKMODULE_SET_QUICK_STREAM://快速开启或关闭流。

		stream = *((u32 *)arg);

		if (stream)
			ret = gc2053_write_reg(gc2053->client, GC2053_REG_CTRL_MODE,
					       GC2053_MODE_STREAMING);
		else
			ret = gc2053_write_reg(gc2053->client, GC2053_REG_CTRL_MODE,
					       GC2053_MODE_SW_STANDBY);
		break;
	default:
		ret = -ENOTTY;
		break;
	}
	return ret;
}

#ifdef CONFIG_COMPAT
static long gc2053_compat_ioctl32(struct v4l2_subdev *sd,
				  unsigned int cmd, unsigned long arg)
{
	void __user *up = compat_ptr(arg);
	struct rkmodule_inf *inf;
	struct rkmodule_awb_cfg *awb_cfg;
	struct rkmodule_lsc_cfg *lsc_cfg;
	struct rkmodule_hdr_cfg *hdr;
	long ret = 0;
	u32 cg = 0;
	u32 stream = 0;

	switch (cmd) {
	case RKMODULE_GET_MODULE_INFO:
		inf = kzalloc(sizeof(*inf), GFP_KERNEL);
		if (!inf) {
			ret = -ENOMEM;
			return ret;
		}

		ret = gc2053_ioctl(sd, cmd, inf);
		if (!ret)
			ret = copy_to_user(up, inf, sizeof(*inf));
		kfree(inf);
		break;
	case RKMODULE_AWB_CFG:
		awb_cfg = kzalloc(sizeof(*awb_cfg), GFP_KERNEL);
		if (!awb_cfg) {
			ret = -ENOMEM;
			return ret;
		}

		ret = copy_from_user(awb_cfg, up, sizeof(*awb_cfg));
		if (!ret)
			ret = gc2053_ioctl(sd, cmd, awb_cfg);
		kfree(awb_cfg);
		break;
	case RKMODULE_LSC_CFG:
		lsc_cfg = kzalloc(sizeof(*lsc_cfg), GFP_KERNEL);
		if (!lsc_cfg) {
			ret = -ENOMEM;
			return ret;
		}

		ret = copy_from_user(lsc_cfg, up, sizeof(*lsc_cfg));
		if (!ret)
			ret = gc2053_ioctl(sd, cmd, lsc_cfg);
		kfree(lsc_cfg);
		break;
	case RKMODULE_GET_HDR_CFG:
		hdr = kzalloc(sizeof(*hdr), GFP_KERNEL);
		if (!hdr) {
			ret = -ENOMEM;
			return ret;
		}

		ret = gc2053_ioctl(sd, cmd, hdr);
		if (!ret)
			ret = copy_to_user(up, hdr, sizeof(*hdr));
		kfree(hdr);
		break;
	case RKMODULE_SET_HDR_CFG:
		hdr = kzalloc(sizeof(*hdr), GFP_KERNEL);
		if (!hdr) {
			ret = -ENOMEM;
			return ret;
		}

		ret = copy_from_user(hdr, up, sizeof(*hdr));
		if (!ret)
			ret = gc2053_ioctl(sd, cmd, hdr);
		kfree(hdr);
		break;
	case RKMODULE_SET_CONVERSION_GAIN:
		ret = copy_from_user(&cg, up, sizeof(cg));
		if (!ret)
			ret = gc2053_ioctl(sd, cmd, &cg);
		break;
	case RKMODULE_SET_QUICK_STREAM:
		ret = copy_from_user(&stream, up, sizeof(u32));
		if (!ret)
			ret = gc2053_ioctl(sd, cmd, &stream);
		break;
	default:
		ret = -ENOTTY;
		break;
	}
	return ret;
}
#endif
/*
是V4L2子设备的流控制操作函数。
这个函数用于启动或停止子设备的视频流。在V4L2框架中，流控制操作是用于管理视频捕获设备数据流的开始和结束的重要接口。
*/
static int gc2053_s_stream(struct v4l2_subdev *sd, int on)
{
	struct gc2053 *gc2053 = to_gc2053(sd);
	struct i2c_client *client = gc2053->client;
	int ret = 0;

	mutex_lock(&gc2053->mutex);
	/*通过将 on 的值转换为布尔值（非零为真，零为假），
	并检查当前流状态是否与请求的状态一致。如果状态没有改变，则直接跳转到解锁互斥量并返回的标签。*/
	on = !!on;
	if (on == gc2053->streaming)
		goto unlock_and_return;

	if (on) {
		/*如果 on 为真（启动流）：尝试打开设备的电源，并同步设备。如果操作失败，关闭设备电源并跳转到错误处理标签。*/
		ret = pm_runtime_get_sync(&client->dev);
		if (ret < 0) {
			pm_runtime_put_noidle(&client->dev);
			goto unlock_and_return;
		}
		/*调用 __gc2053_start_stream 函数实际启动流。如果启动失败，记录错误信息，关闭设备电源，并跳转到错误处理标签。*/
		ret = __gc2053_start_stream(gc2053);
		if (ret) {
			v4l2_err(sd, "start stream failed while write regs\n");
			pm_runtime_put(&client->dev);
			goto unlock_and_return;
		}
	} else {
		/*如果 on 为假（停止流）：调用 __gc2053_stop_stream 函数停止流，然后关闭设备电源。*/
		__gc2053_stop_stream(gc2053);
		pm_runtime_put(&client->dev);
	}
//更新 gc2053 结构体中的 streaming 标志，以反映当前的流状态。
	gc2053->streaming = on;

unlock_and_return:
	mutex_unlock(&gc2053->mutex);
	return 0;
}

static int gc2053_g_frame_interval(struct v4l2_subdev *sd,
				   struct v4l2_subdev_frame_interval *fi)
{
	struct gc2053 *gc2053 = to_gc2053(sd);
	const struct gc2053_mode *mode = gc2053->cur_mode;

	mutex_lock(&gc2053->mutex);
	fi->interval = mode->max_fps;
	mutex_unlock(&gc2053->mutex);

	return 0;
}

/*它是V4L2子设备的媒体总线（mbus）配置操作函数
sd 是一个指向 v4l2_subdev 结构体的指针，
代表V4L2子设备；config 是一个指向 v4l2_mbus_config 结构体的指针，用于存储媒体总线配置信息。*/
static int gc2053_g_mbus_config(struct v4l2_subdev *sd,
				struct v4l2_mbus_config *config)
{
	/*获取 gc2053 设备和当前模式信息：
	使用辅助函数 to_gc2053 将 v4l2_subdev 指针转换为 gc2053 设备特定的结构体指针。
	然后获取当前模式信息，该信息定义了子设备的分辨率、帧率等参数。*/
	struct gc2053 *gc2053 = to_gc2053(sd);
	const struct gc2053_mode *mode = gc2053->cur_mode;
	u32 val = 0;
	/*根据当前模式的HDR设置配置媒体总线：
	如果当前模式不支持高动态范围（HDR），则配置媒体总线以使用连续时钟模式。1 << (GC2053_LANES - 1)
	 用于设置车道数量，V4L2_MBUS_CSI2_CHANNEL_0 表示使用的是MIPI CSI-2接口的通道0，
	V4L2_MBUS_CSI2_CONTINUOUS_CLOCK 表示使用连续时钟。*/
	if (mode->hdr_mode == NO_HDR)
		val = 1 << (GC2053_LANES - 1) |
		V4L2_MBUS_CSI2_CHANNEL_0 |
		V4L2_MBUS_CSI2_CONTINUOUS_CLOCK;
	/*填充媒体总线配置结构体：
	设置 config 结构体的 type 字段为 V4L2_MBUS_CSI2，表示使用的是CSI-2接口。
	flags 字段被设置为之前计算的 val，包含了车道数量和时钟模式的配置。*/
	config->type = V4L2_MBUS_CSI2;
	config->flags = val;
	return 0;
}
static int gc2053_enum_mbus_code(struct v4l2_subdev *sd,
				 struct v4l2_subdev_pad_config *cfg,
				 struct v4l2_subdev_mbus_code_enum *code)
{
	if (code->index != 0)
		return -EINVAL;
	code->code = GC2053_MEDIA_BUS_FMT;
	return 0;
}

static int gc2053_enum_frame_sizes(struct v4l2_subdev *sd,
				   struct v4l2_subdev_pad_config *cfg,
				   struct v4l2_subdev_frame_size_enum *fse)
{
	struct gc2053 *gc2053 = to_gc2053(sd);

	if (fse->index >= gc2053->cfg_num)
		return -EINVAL;

	if (fse->code != GC2053_MEDIA_BUS_FMT)
		return -EINVAL;

	fse->min_width  = supported_modes[fse->index].width;
	fse->max_width  = supported_modes[fse->index].width;
	fse->max_height = supported_modes[fse->index].height;
	fse->min_height = supported_modes[fse->index].height;
	return 0;
}

static int gc2053_enum_frame_interval(struct v4l2_subdev *sd,
						  struct v4l2_subdev_pad_config *cfg,
						  struct v4l2_subdev_frame_interval_enum *fie)
{
	struct gc2053 *gc2053 = to_gc2053(sd);

	if (fie->index >= gc2053->cfg_num)
		return -EINVAL;

	fie->code = GC2053_MEDIA_BUS_FMT;
	fie->width = supported_modes[fie->index].width;
	fie->height = supported_modes[fie->index].height;
	fie->interval = supported_modes[fie->index].max_fps;
	fie->reserved[0] = supported_modes[fie->index].hdr_mode;
	return 0;
}

static int gc2053_set_fmt(struct v4l2_subdev *sd,
			  struct v4l2_subdev_pad_config *cfg,
			  struct v4l2_subdev_format *fmt)
{
	struct gc2053 *gc2053 = to_gc2053(sd);
	const struct gc2053_mode *mode;
	s64 h_blank, vblank_def;

	mutex_lock(&gc2053->mutex);

	mode = gc2053_find_best_fit(gc2053, fmt);
	fmt->format.code = GC2053_MEDIA_BUS_FMT;
	fmt->format.width = mode->width;
	fmt->format.height = mode->height;
	fmt->format.field = V4L2_FIELD_NONE;
	if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
#ifdef CONFIG_VIDEO_V4L2_SUBDEV_API
		*v4l2_subdev_get_try_format(sd, cfg, fmt->pad) = fmt->format;
#else
		mutex_unlock(&gc2053->mutex);
		return -ENOTTY;
#endif
	} else {
		gc2053->cur_mode = mode;
		h_blank = mode->hts_def - mode->width;
		__v4l2_ctrl_modify_range(gc2053->hblank, h_blank,
					 h_blank, 1, h_blank);
		vblank_def = mode->vts_def - mode->height;
		__v4l2_ctrl_modify_range(gc2053->vblank, vblank_def,
					 GC2053_VTS_MAX - mode->height,
					 1, vblank_def);
	}

	mutex_unlock(&gc2053->mutex);
	return 0;
}

//用于获取子设备当前的视频格式信息，如分辨率、像素格式等
static int gc2053_get_fmt(struct v4l2_subdev *sd,
			  struct v4l2_subdev_pad_config *cfg,
			  struct v4l2_subdev_format *fmt)
{
	struct gc2053 *gc2053 = to_gc2053(sd);
	const struct gc2053_mode *mode = gc2053->cur_mode;

	mutex_lock(&gc2053->mutex);
	/*处理格式尝试（TRY）操作：
	如果传入的 fmt 参数的 which 字段表示尝试操作（V4L2_SUBDEV_FORMAT_TRY），则尝试获取一个兼容的格式。*/
	if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
#ifdef CONFIG_VIDEO_V4L2_SUBDEV_API
/*获取尝试格式：
如果系统配置了V4L2子设备API（CONFIG_VIDEO_V4L2_SUBDEV_API），
则调用 v4l2_subdev_get_try_format 函数获取尝试格式，并将其存储在 fmt->format 中。*/
		fmt->format = *v4l2_subdev_get_try_format(sd, cfg, fmt->pad);
#else
		mutex_unlock(&gc2053->mutex);
		return -ENOTTY;
#endif
	} else {//设置 fmt 结构体的 format 字段，包括宽度、高度、媒体总线格式代码和场类型。
		fmt->format.width = mode->width;
		fmt->format.height = mode->height;
		fmt->format.code = GC2053_MEDIA_BUS_FMT;
		fmt->format.field = V4L2_FIELD_NONE;

		/*根据 fmt->pad 和当前模式的HDR设置，设置 fmt->reserved 字段，
		这通常用于存储额外的格式相关信息，如虚拟通道（virtual channel）。*/
		/* format info: width/height/data type/virctual channel */
		if (fmt->pad < PAD_MAX && mode->hdr_mode != NO_HDR)
			fmt->reserved[0] = mode->vc[fmt->pad];
		else
			fmt->reserved[0] = mode->vc[PAD0];

	}
	mutex_unlock(&gc2053->mutex);
	return 0;
}

#ifdef CONFIG_VIDEO_V4L2_SUBDEV_API
static int gc2053_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
	struct gc2053 *gc2053 = to_gc2053(sd);
	struct v4l2_mbus_framefmt *try_fmt =
				v4l2_subdev_get_try_format(sd, fh->pad, 0);
	const struct gc2053_mode *def_mode = &supported_modes[0];

	mutex_lock(&gc2053->mutex);
	/* Initialize try_fmt */
	try_fmt->width = def_mode->width;
	try_fmt->height = def_mode->height;
	try_fmt->code = GC2053_MEDIA_BUS_FMT;
	try_fmt->field = V4L2_FIELD_NONE;

	mutex_unlock(&gc2053->mutex);
	/* No crop or compose */
	return 0;
}
#endif

#ifdef CONFIG_VIDEO_V4L2_SUBDEV_API
static const struct v4l2_subdev_internal_ops gc2053_internal_ops = {
	.open = gc2053_open,
};
#endif

static int gc2053_s_power(struct v4l2_subdev *sd, int on)
{
	struct gc2053 *gc2053 = to_gc2053(sd);
	struct i2c_client *client = gc2053->client;
	int ret = 0;

	mutex_lock(&gc2053->mutex);

	/* If the power state is not modified - no work to do. */
	//如果当前的电源状态已经与请求的状态一致，则无需执行任何操作，直接跳转到解锁互斥量并返回的标签。
	if (gc2053->power_on == !!on)
		goto unlock_and_return;
  //如果 on 非零（开启电源）：
  //使用 pm_runtime_get_sync 函数尝试开启电源，
  //并同步设备。如果操作失败，使用 pm_runtime_put_noidle 关闭电源，并跳转到错误处理标签。
	if (on) {
		ret = pm_runtime_get_sync(&client->dev);
		if (ret < 0) {
			pm_runtime_put_noidle(&client->dev);
			goto unlock_and_return;
		}

		gc2053->power_on = true;
	} else {
		/*如果 on 为零（关闭电源）：使用 pm_runtime_put 函数关闭电源，并更新 gc2053 结构体中的 power_on 标志。*/
		pm_runtime_put(&client->dev);
		gc2053->power_on = false;
	}

unlock_and_return:
	mutex_unlock(&gc2053->mutex);

	return ret;
}

static const struct v4l2_subdev_core_ops gc2053_core_ops = {
	/*是一个函数指针，指向名为 gc2053_s_power 的函数。这个函数负责处理子设备的电源管理，
	例如打开或关闭设备的电源。在V4L2中，s_power 操作通常与设备的电源状态管理相关，允许驱动程序控制设备的电源状态。*/
	.s_power = gc2053_s_power,
	/*是一个函数指针，指向名为 gc2053_ioctl 的函数。这个函数处理对子设备的输入输出控制命令（ioctl）。
	在Linux系统中，ioctl是一种通用的设备控制接口，
	允许用户空间的程序向内核中的驱动程序发送特定的控制命令，以执行各种操作，如查询设备能力、设置设备参数等。*/
	.ioctl = gc2053_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl32 = gc2053_compat_ioctl32,
#endif
};

/*它是一个V4L2子设备的视音频操作集合。在V4L2框架中，视音频操作集合包含了与视频捕获和处理相关的操作函数。
这些操作函数使得用户空间的应用程序能够控制视频捕获设备的行为，
如开始或停止数据流、获取帧间隔时间、获取媒体总线（mbus）配置等。*/
static const struct v4l2_subdev_video_ops gc2053_video_ops = {
	/*是一个函数指针，指向名为 gc2053_s_stream 的函数。这个函数负责开始（启动）或停止（暂停）视频流。
	当用户空间的应用程序调用V4L2 API来开始或停止视频捕获时，V4L2核心会调用这个函数*/
	.s_stream = gc2053_s_stream,
	/*是一个函数指针，指向名为 gc2053_g_frame_interval 的函数。这个函数用于获取两帧之间的时间间隔，即帧率。
	应用程序可以使用这个信息来了解设备在当前设置下的输出帧率。*/
	.g_frame_interval = gc2053_g_frame_interval,
	/*是一个函数指针，指向名为 gc2053_g_mbus_config 的函数。这个函数用于获取媒体总线（mbus）的配置信息，
	这通常包括数据通道的数量、数据格式、时钟频率等。
	媒体总线配置对于正确处理从传感器到处理器的数据流非常重要。*/
	.g_mbus_config = gc2053_g_mbus_config,
};

/*它是一个V4L2子设备的媒体总线（mbus）接口操作集合。在V4L2框架中，
媒体总线接口操作集合包含了与子设备的媒体总线接口相关的操作函数，这些操作用于管理数据流的格式、大小和时间间隔等。*/
static const struct v4l2_subdev_pad_ops gc2053_pad_ops = {
	/*.enum_mbus_code 字段是一个函数指针，指向名为 gc2053_enum_mbus_code 的函数。
	这个函数负责枚举和设置媒体总线的数据格式代码，例如YUV、RGB等。*/
	.enum_mbus_code = gc2053_enum_mbus_code,
	/*enum_frame_size 字段是一个函数指针，指向名为 gc2053_enum_frame_sizes 的函数。
	这个函数负责枚举和设置帧的大小，即分辨率。*/
	.enum_frame_size = gc2053_enum_frame_sizes,
	/*enum_frame_interval 字段是一个函数指针，指向名为 gc2053_enum_frame_interval 的函数。
	这个函数负责枚举和设置帧之间的时间间隔，通常与帧率相关。*/
	.enum_frame_interval = gc2053_enum_frame_interval,
	/*get_fmt 字段是一个函数指针，指向名为 gc2053_get_fmt 的函数。
	这个函数用于获取当前设置的媒体总线格式，包括像素格式和数据格式。*/
	.get_fmt = gc2053_get_fmt,
	/*set_fmt 字段是一个函数指针，指向名为 gc2053_set_fmt 的函数。
	这个函数用于设置媒体总线的格式，允许更改像素格式或其他与数据流相关的格式设置。*/
	.set_fmt = gc2053_set_fmt,
/*gc2053_pad_ops 结构体通过定义这些媒体总线接口操作函数，为 gc2053 子设备的媒体总线接口提供了一系列的控制接口。
这些接口允许V4L2核心API以及用户空间的应用程序与子设备的媒体总线接口进行交互，
执行数据格式的枚举、设置和查询操作。这样的设计使得子设备的媒体总线接口能够被正确地控制和管理。*/	
};

static const struct v4l2_subdev_ops gc2053_subdev_ops = {
	/*.core 字段是一个指向 gc2053_core_ops 的指针，后者是一个包含了核心操作的函数集合。
	/停止数据流）等基本操作。
	gc2053_core_ops 应该是在其他地这些核心操作通常包括子设备的初始化、关闭、流控制（开启方定义的一个结构体，它实现了V4L2子设备核心操作的接口。*/
	.core   = &gc2053_core_ops,
	/*video 字段是一个指向 gc2053_video_ops 的指针，后者定义了与视频相关的操作。
	这可能包括控制曝光、设置帧率、调整格式等与视频捕获直接相关的功能。
	gc2053_video_ops 同样是一个在其他地方定义的结构体，实现了V4L2子设备视频操作的接口。*/
	.video  = &gc2053_video_ops,
	/*pad 字段指向 gc2053_pad_ops，这是一个包含了与子设备的数据接口（pad）相关的操作的函数集合。
	在V4L2中，pad是子设备的一个概念，代表数据流的输入或输出点。
	这些操作可能包括配置数据流的格式、处理数据传输等。gc2053_pad_ops 是一个结构体，实现了V4L2子设备pad操作的接口。 */
	.pad    = &gc2053_pad_ops,
};

static int gc2053_runtime_resume(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct gc2053 *gc2053 = to_gc2053(sd);

	__gc2053_power_on(gc2053);
	return 0;
}
/*
to_i2c_client函数的作用是根据给定的设备结构体指针，返回对应的I2C设备客户端结构体指针。
这个函数在内核驱动程序中经常被用来获取I2C设备的相关信息并进行操作。 
具体来说，to_i2c_client函数接受一个指向设备结构体的指针作为参数，然后通过内部的转换逻辑，
将其转换为I2C设备客户端结构体指针。
这样，驱动程序就可以使用返回的I2C设备客户端结构体指针来访问和操作I2C设备的属性和功能。

i2c_get_clientdata函数的作用是根据给定的I2C设备客户端结构体指针，返回该结构体中存储的私有数据指针。
这个函数在内核驱动程序中经常被用来获取I2C设备客户端结构体中存储的私有数据，以便在驱动程序中进行操作。 

to_gc2053函数的作用是根据给定的V4L2子设备结构体指针，返回对应的GC2053图像传感器设备结构体指针。通过这个函数，
驱动程序可以使用返回的GC2053图像传感器设备结构体指针来访问和操作GC2053图像传感器的属性和功能。 

*/
static int gc2053_runtime_suspend(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct gc2053 *gc2053 = to_gc2053(sd);

	__gc2053_power_off(gc2053);
	return 0;
}
/*
SET_RUNTIME_PM_OPS：
对于runtime PM，默认状态下设备的状态是suspend，如果硬件上它是运行状态，
需要调用pm_runtime_set_active()来修改它的状态，然后调用pm_runtime_enable()来使能runtime PM。
一般是在probe()的结尾处使用，以为它可能导致runtime的suspend/resume函数立即调用。
一般在驱动remove中调用pm_runtime_disable()
*/
static const struct dev_pm_ops gc2053_pm_ops = {
	SET_RUNTIME_PM_OPS(gc2053_runtime_suspend,
					   gc2053_runtime_resume, NULL)
};

/*
它是一个I2C设备驱动程序的探测（probe）函数。在Linux内核中，
当一个I2C设备被系统识别时，这个函数会被调用来初始化和注册设备
client 是一个指向 i2c_client 结构体的指针，代表I2C通信的客户端（即摄像头传感器设备）；
id 是一个指向 i2c_device_id 结构体的指针，包含了设备的识别信息。
*/
static int gc2053_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	//获取与I2C客户端关联的设备结构体和设备树节点。
	struct device *dev = &client->dev;
	struct device_node *node = dev->of_node;
	struct gc2053 *gc2053;
	struct v4l2_subdev *sd;
	char facing[2];
	int ret;

/*
KERNEL_VERSION是一个宏定义，用于表示内核版本号
内核版本号通常由三个数字组成，分别表示主版本号、次版本号和修订版本号。
例如，内核版本号3.18.1中，3表示主版本号，18表示次版本号，1表示修订版本号

主版本号：0x000000 << 16 = 0x00000000 
次版本号：0x000001 << 8 = 0x00000100 
修订版本号：0x000001 

DRIVER_VERSION = 0x00000000 | 0x00000100 | 0x000001 = 0x00000101

dev_info函数来输出驱动程序的版本信息。dev_info函数的第一个参数是指向设备结构体的指针，
表示要输出信息的设备。第二个参数是一个格式化字符串，用于指定输出信息的格式。 


*/
	dev_info(dev, "driver version: %02x.%02x.%02x",
		DRIVER_VERSION >> 16,
		(DRIVER_VERSION & 0xff00) >> 8,
		DRIVER_VERSION & 0x00ff);

	/*
	分配的内存可以跟设备进行绑定，当设备跟驱动分离时，跟设备绑定的内存会被自动释放，不需要我们手动释放。当然，如果内存不再使用了，我们也可以使用函数devm_kfree()手动进行释放。
	static inline void *devm_kzalloc(struct device *dev, size_t size, gfp_t gfp)
   {
	return devm_kmalloc(dev, size, gfp | __GFP_ZERO);
   }
	dev是内存需要绑定到的设备；size是需要分配的内存大小（单位为字节）；gfp设置这片内存的类型标志，在驱动程序里面设置为GFP_KERNEL即可，其定义位于include/linux/gfp.h中。
	*/	
	//使用 devm_kzalloc 函数分配内存并初始化 gc2053 设备结构体。这个函数会将分配的内存与设备绑定，确保在设备卸载时自动释放内存。
	gc2053 = devm_kzalloc(dev, sizeof(*gc2053), GFP_KERNEL);
	if (!gc2053)
		return -ENOMEM;
//通过of_property_read_u32获取设备树节点信息，以下代码为获取设备树内的相机模组名、hdr参数等
	gc2053->client = client;
	//使用 of_property_read_u32 函数从设备树中读取属性，并存储到 gc2053 结构体中。
	ret = of_property_read_u32(node, RKMODULE_CAMERA_MODULE_INDEX,
				   &gc2053->module_index);
	ret |= of_property_read_string(node, RKMODULE_CAMERA_MODULE_FACING,
					   &gc2053->module_facing);
	ret |= of_property_read_string(node, RKMODULE_CAMERA_MODULE_NAME,
					   &gc2053->module_name);
	ret |= of_property_read_string(node, RKMODULE_CAMERA_LENS_NAME,
					   &gc2053->len_name);
	if (ret) {
		dev_err(dev,
			"could not get module information!\n");
		return -EINVAL;
	}
	/*获取时钟和GPIO资源：
	使用 devm_clk_get 和 devm_gpiod_get 函数获取设备的时钟和GPIO资源。*/

	gc2053->xvclk = devm_clk_get(&client->dev, "xvclk");
	if (IS_ERR(gc2053->xvclk)) {
		dev_err(&client->dev, "Failed to get xvclk\n");
		return -EINVAL;
	}

	gc2053->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_LOW);
	if (IS_ERR(gc2053->reset_gpio))
		dev_warn(dev, "Failed to get reset-gpios\n");

	gc2053->pwdn_gpio = devm_gpiod_get(dev, "pwdn", GPIOD_OUT_LOW);
	if (IS_ERR(gc2053->pwdn_gpio))
		dev_info(dev, "Failed to get pwdn-gpios, maybe no used\n");

	gc2053->power_gpio = devm_gpiod_get(dev, "power", GPIOD_OUT_LOW);
	if (IS_ERR(gc2053->power_gpio))
		dev_warn(dev, "Failed to get power-gpios\n");
//调用 gc2053_configure_regulators 函数配置设备的电源管理。
	ret = gc2053_configure_regulators(gc2053);
	if (ret) {
		dev_err(dev, "Failed to get power regulators\n");
		return ret;
	}

	ret = gc2053_parse_of(gc2053);
	if (ret != 0)
		return -EINVAL;

	gc2053->pinctrl = devm_pinctrl_get(dev);
	if (!IS_ERR(gc2053->pinctrl)) {
		gc2053->pins_default =
			pinctrl_lookup_state(gc2053->pinctrl,
						 OF_CAMERA_PINCTRL_STATE_DEFAULT);
		if (IS_ERR(gc2053->pins_default))
			dev_err(dev, "could not get default pinstate\n");

		gc2053->pins_sleep =
			pinctrl_lookup_state(gc2053->pinctrl,
						 OF_CAMERA_PINCTRL_STATE_SLEEP);
		if (IS_ERR(gc2053->pins_sleep))
			dev_err(dev, "could not get sleep pinstate\n");
	} else {
		dev_err(dev, "no pinctrl\n");
	}

	mutex_init(&gc2053->mutex);

	sd = &gc2053->subdev;
	v4l2_i2c_subdev_init(sd, client, &gc2053_subdev_ops);//使用 v4l2_i2c_subdev_init 函数初始化 gc2053 子设备
	ret = gc2053_initialize_controls(gc2053);//初始化 gc2053 子设备的V4L2控件。这些控件允许用户空间的应用程序通过V4L2 API控制摄像头的各种参数，如曝光、增益等。
	if (ret)
		goto err_destroy_mutex;
   //调用 __gc2053_power_on 函数来启动传感器的电源，使其进入工作状态。
	ret = __gc2053_power_on(gc2053);
	if (ret)
		goto err_free_handler;
//调用 gc2053_check_sensor_id 函数来验证传感器的身份。这通常涉及读取传感器的ID寄存器，并与已知的ID进行比较。
	ret = gc2053_check_sensor_id(gc2053, client);
	if (ret)
		goto err_power_off;

#ifdef CONFIG_VIDEO_V4L2_SUBDEV_API
	sd->internal_ops = &gc2053_internal_ops;
	sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
#endif
#if defined(CONFIG_MEDIA_CONTROLLER)
	gc2053->pad.flags = MEDIA_PAD_FL_SOURCE;
	sd->entity.function = MEDIA_ENT_F_CAM_SENSOR;
	ret = media_entity_pads_init(&sd->entity, 1, &gc2053->pad);
	if (ret < 0)
		goto err_power_off;
#endif
/*根据 gc2053->module_facing 的值（通常是 "back" 或 "front"），
设置 facing 字符串。然后使用 snprintf 函数设置子设备的名称，包括模块索引、朝向和传感器名称。*/
	memset(facing, 0, sizeof(facing));
	if (strcmp(gc2053->module_facing, "back") == 0)
		facing[0] = 'b';
	else
		facing[0] = 'f';

	snprintf(sd->name, sizeof(sd->name), "m%02d_%s_%s %s",
		 gc2053->module_index, facing,
		 GC2053_NAME, dev_name(sd->dev));
/*注册子设备：
使用 v4l2_async_register_subdev_sensor_common 函数异步注册子设备。这样，用户空间的应用程序就可以通过V4L2 API与之交互。*/
	ret = v4l2_async_register_subdev_sensor_common(sd);
	if (ret) {
		dev_err(dev, "v4l2 async register subdev failed\n");
		goto err_clean_entity;
	}
//使用 pm_runtime_* 函数管理设备的电源运行时状态，这有助于在设备不活跃时节省电能。
	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);
	pm_runtime_idle(dev);

	return 0;

err_clean_entity:
#if defined(CONFIG_MEDIA_CONTROLLER)
	media_entity_cleanup(&sd->entity);
#endif

err_power_off:
	__gc2053_power_off(gc2053);
err_free_handler:
	v4l2_ctrl_handler_free(&gc2053->ctrl_handler);

err_destroy_mutex:
	mutex_destroy(&gc2053->mutex);
	return ret;
}

static int gc2053_remove(struct i2c_client *client)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct gc2053 *gc2053 = to_gc2053(sd);

	v4l2_async_unregister_subdev(sd);
#if defined(CONFIG_MEDIA_CONTROLLER)
	media_entity_cleanup(&sd->entity);
#endif
	v4l2_ctrl_handler_free(&gc2053->ctrl_handler);
	mutex_destroy(&gc2053->mutex);

	pm_runtime_disable(&client->dev);
	if (!pm_runtime_status_suspended(&client->dev))
		__gc2053_power_off(gc2053);
	pm_runtime_set_suspended(&client->dev);
	return 0;
}

static const struct i2c_device_id gc2053_match_id[] = {
	{ "gc2053", 0 },
	{ },
};

#if IS_ENABLED(CONFIG_OF)
static const struct of_device_id gc2053_of_match[] = {
	{ .compatible = "galaxycore,gc2053" },
	{},
};
MODULE_DEVICE_TABLE(of, gc2053_of_match);
#endif

static struct i2c_driver gc2053_i2c_driver = {
	.driver = {
		.name = GC2053_NAME,
		.pm = &gc2053_pm_ops,
		.of_match_table = of_match_ptr(gc2053_of_match),
	},
	.probe      = &gc2053_probe,
	.remove     = &gc2053_remove,
	.id_table   = gc2053_match_id,
};

static int __init sensor_mod_init(void)
{
	return i2c_add_driver(&gc2053_i2c_driver);
}

static void __exit sensor_mod_exit(void)
{
	i2c_del_driver(&gc2053_i2c_driver);
}

device_initcall_sync(sensor_mod_init);
module_exit(sensor_mod_exit);

MODULE_DESCRIPTION("GC2035 CMOS Image Sensor driver");
MODULE_LICENSE("GPL v2");
