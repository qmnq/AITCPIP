#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/* 文件操作 */
#include <fstream>
#include <iostream>
/* Linux系统的日期时间头文件 */
#include <sys/time.h>
/* 使用stb_image图像解码库 */
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"							/* 用于图像加载 */
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb/stb_image_resize.h>				/* 用于改变图像尺寸 */
/* 要用RKNN的API，这个头文件不能少 */
#include "rknn_api.h"

using namespace std;

/*-------------------------------------------
                  功能函数定义
-------------------------------------------*/

/**
打印RKNN模型的Tensor属性

参数：
rknn_tensor_attr *attr是Tensor的属性结构体

uint32_t index;  							输入输出 Tensor 的索引位置                                   
uint32_t n_dims; 							Tensor 维度个数                                  
uint32_t dims[RKNN_MAX_DIMS]; Tensor 各维度值                     
char name[RKNN_MAX_NAME_LEN]; Tensor 名称                     
uint32_t n_elems; 						Tensor 数据元素个数                                 
uint32_t size;   							Tensor 数据所占内存大小                                  
rknn_tensor_format fmt;   		Tensor 维度的格式（NCHW或者NHWC）                   
rknn_tensor_type type;				Tensor 数据类型（FLOAT32、FLOAT16、INT8、INT16、UINT8）                              
rknn_tensor_qnt_type qnt_type;Tensor 量化类型（NONE、DFP、ASYMMETRIC，未量化、动态定点量化、非对称量化）                     
int8_t fl;  									DFP量化类型的参数                                        
uint32_t zp;                  ASYMMETRIC量化类型的参数                      
float scale; 									ASYMMETRIC量化类型的参数 

返回值：无                                     
**/
static void printRKNNTensor(rknn_tensor_attr *attr)
{
    printf("index=%d name=%s n_dims=%d dims=[%d %d %d %d] n_elems=%d size=%d fmt=%d type=%d qnt_type=%d fl=%d zp=%d scale=%f\n",
           attr->index, attr->name, attr->n_dims, attr->dims[3], attr->dims[2], attr->dims[1], attr->dims[0],
           attr->n_elems, attr->size, 0, attr->type, attr->qnt_type, attr->fl, attr->zp, attr->scale);
}

/**
加载模型文件（.rknn文件）

参数：
*filename：模型文件的路径
*model_size：模型文件的大小

返回值：model，为char类型
**/
static unsigned char *load_model(const char *filename, int *model_size)
{
		/* 以只读形式打开模型二进制文件，r表示读，b表示二进制文件 */
    FILE *fp = fopen(filename, "rb");
    if (fp == nullptr)
    {
        printf("fopen %s fail!\n", filename);
        return NULL;
    }
		/* 文件指针定位到文件末尾，偏移0个字节 */
    fseek(fp, 0, SEEK_END);
		/* 获取文件指针位置相对于文件首部的偏移字节数，即获取文件的大小 */
    int model_len = ftell(fp);
		/* 为模型申请内存，内存大小是文件的大小model_len */
    unsigned char *model = (unsigned char *)malloc(model_len);
		/* 文件指针放在文件头部 */
    fseek(fp, 0, SEEK_SET);
		/* 从文件头部以字节为单位读取长度为model_len的数据到内存model中 */
    if (model_len != fread(model, 1, model_len, fp))
    {
        printf("fread %s fail!\n", filename);
        free(model);
        return NULL;
    }
    *model_size = model_len;
    if (fp)
    {
        fclose(fp);/* 关闭文件 */
    }
    return model; /* 返回读取的模型的二进制数据 */
}

/*-------------------------------------------
            这个函数比较难理解
-------------------------------------------*/
/**
获取模型推理的top5结果

参数：
*pfProb：输出数据 Buffer 的指针
*pfMaxProb：top5的概率
pMaxClass：top5的类别 
outputCount：转为float32 数据后的大小
topNum：打印的类的个数，top5就是5个

返回值：成功1，失败0
**/
static int rknn_GetTop(
    float *pfProb, 				/* 输出数据 Buffer 的指针，为概率值 */
    float *pfMaxProb,			/* top5概率指针 */
    uint32_t *pMaxClass,	/* top5类别指针 */
		/* 为什么要除以4？因为want_float=1 时，想要的是 float32 数据，大小是元素数量*4 字节 */
    uint32_t outputCount,	/* 输出数据 Buffer 所占内存大小/4（应该等于类的个数，有1000类？） */  
    uint32_t topNum)			/* top5,输出5个 */
{
    uint32_t i, j;

#define MAX_TOP_NUM 20
    if (topNum > MAX_TOP_NUM)
        return 0;

    memset(pfMaxProb, 0, sizeof(float) * topNum);
    memset(pMaxClass, 0xff, sizeof(float) * topNum);

    for (j = 0; j < topNum; j++)
    {
				/* 以下2句print的代码是自己添加的，打印信息看看
				测试时打印下面的语句5次：
				outputCount= 1001
				*pMaxClass=-1362380700
				*/
				printf("outputCount= %3d \n",outputCount);
        printf("*pMaxClass=%3d \n",&pMaxClass);
				
        for (i = 0; i < outputCount; i++)/* 1000类 */
        {
            if ((i == *(pMaxClass + 0)) || (i == *(pMaxClass + 1)) || (i == *(pMaxClass + 2)) ||
                (i == *(pMaxClass + 3)) || (i == *(pMaxClass + 4)))
            {
                continue;
            }

						/* 排序，从高到低排序，排5位 */
            if (pfProb[i] > *(pfMaxProb + j))
            {
								/* 以下print的代码是自己添加的，打印信息看看
								测试时打印下面的语句5次：
								*(pfProb[i] + 0)=0.000062
								*(pfProb[i] + 0)=0.000573
								*(pfProb[i] + 0)=0.000876
								*(pfProb[i] + 0)=0.083862
								*(pfProb[i] + 0)=0.865723
								*/
								printf("*(pfProb[i] + 0)=\n"，pfProb[i]);
                *(pfMaxProb + j) = pfProb[i]; /* 概率 */
                *(pMaxClass + j) = i;					/* 标签 */
            }
        }
    }

    return 1;
}

/**
加载图片，并重置图片大小

参数：
*image_path：图片的绝对路径
*input_attr：Tensor的属性结构体指针

返回值：图片数据image_data，为char类型
**/
static unsigned char *load_image(const char *image_path, rknn_tensor_attr *input_attr)
{
    int req_height = 0;		/* Tensor属性中图片的高 */
    int req_width = 0;		/* Tensor属性中图片的宽 */
    int req_channel = 0;	/* Tensor属性中图片的通道数 */
		
		/* 根据Tensor的属性中数据的格式是NCHW或者NHWC来处理图片 */ 
    switch (input_attr->fmt)
    {
    case RKNN_TENSOR_NHWC:
        req_height = input_attr->dims[2];
        req_width = input_attr->dims[1];
        req_channel = input_attr->dims[0];
        break;
    case RKNN_TENSOR_NCHW:
        req_height = input_attr->dims[1];
        req_width = input_attr->dims[0];
        req_channel = input_attr->dims[2];
        break;
    default:
        printf("meet unsupported layout\n");
        return NULL;
    }
		/* 打印图片的W、H、C和Tensor的属性中数据的格式 */
    printf("w=%d,h=%d,c=%d, fmt=%d\n", req_width, req_height, req_channel, input_attr->fmt);

    int height = 0;
    int width = 0;
    int channel = 0;
		
		/* 加载图片并解码，image_path是图片路径，stbi_load解析出来的图片数据放在 &width, &height, &channel里，req_channel是你期望的通道数 */
    unsigned char *image_data = stbi_load(image_path, &width, &height, &channel, req_channel);
    if (image_data == NULL)
    {
        printf("load image failed!\n");
        return NULL;
    }
		/* 如果解码得到的图片和Tensor属性中的图片宽高不一样，就重新设置图片大小 */
    if (width != req_width || height != req_height)
    {
				/* 申请内存image_resized的大小为Tensor属性中图片的像素个数 */
        unsigned char *image_resized = (unsigned char *)STBI_MALLOC(req_width * req_height * req_channel);
        if (!image_resized)
        {
            printf("malloc image failed!\n");
            STBI_FREE(image_data);
            return NULL;
        }
				/* 使用stbir_resize_uint8()对图像进行缩放，参数依次为：输入图像数据指针、输入图像宽、
				输入图像高、输入图像步长(若为0则为宽x通道数)、输出图像数据指针、输出图像宽、输出图像高、
				输出图像步长(若为0则为宽*通道数)、图像通道数(输入与输出一致)，此函数正常返回1，否则返回0；*/
        if (stbir_resize_uint8(image_data, width, height, 0, image_resized, req_width, req_height, 0, channel) != 1)
        {
            printf("resize image failed!\n");
            STBI_FREE(image_data);
            return NULL;
        }
				/* STBI_FREE和STBI_MALLOC，free内存 */
        STBI_FREE(image_data);
				/* 返回的image_data是经过图像缩放后的图像 */
        image_data = image_resized;
    }

    return image_data;
}



int main(int argc, char **argv)
{
    rknn_context ctx;
    int ret;
    int model_len = 0;
    unsigned char *model;
		
		/* ./rknn_mobilenet_demo model/mobilenet_v1_rv1109_rv1126.rknn model/cat_224x224.jpg
		argv[0]是./rknn_mobilenet_demo
		argv[1]是model/mobilenet_v1_rv1109_rv1126.rknn
		argv[2]是model/cat_224x224.jpg
		*/
    const char *model_path = argv[1];
    const char *img_path = argv[2];

    /* 加载RKNN模型，返回值是RKNN 模型的二进制数据 */
    model = load_model(model_path, &model_len);
		/* 初始化RKNN：创建 rknn_context 对象、加载 RKNN 模型以及
		根据 flag 执行特定的初始化行为 */
    ret = rknn_init(&ctx, model, model_len, 0);
    if (ret < 0)
    {
        printf("rknn_init fail! ret=%d\n", ret);
        return -1;
    }

    // Get Model Input Output Info
    rknn_input_output_num io_num;
		/* 查询获取到模型输入输出、运行时间以及 SDK 版本等信息，
		RKNN_QUERY_IN_OUT_NUM是查询输入输出 Tensor 个数，只加载一个模型的话，个数就是1 */
    ret = rknn_query(ctx, RKNN_QUERY_IN_OUT_NUM, &io_num, sizeof(io_num));
    if (ret != RKNN_SUCC)
    {
        printf("rknn_query fail! ret=%d\n", ret);
        return -1;
    }
    printf("model input num: %d, output num: %d\n", io_num.n_input, io_num.n_output);

		/* 输入 Tensor 的属性 */
    printf("input tensors:\n");
    rknn_tensor_attr input_attrs[io_num.n_input];
    memset(input_attrs, 0, sizeof(input_attrs));
    for (int i = 0; i < io_num.n_input; i++)
    {
        input_attrs[i].index = i;
				/* RKNN_QUERY_INPUT_ATTR是输入 Tensor 属性 */
        ret = rknn_query(ctx, RKNN_QUERY_INPUT_ATTR, &(input_attrs[i]), sizeof(rknn_tensor_attr));
        if (ret != RKNN_SUCC)
        {
            printf("rknn_query fail! ret=%d\n", ret);
            return -1;
        }
				/* 打印输入的Tensor 属性 */
        printRKNNTensor(&(input_attrs[i]));
    }
		/* 输出 Tensor 的属性 */
    printf("output tensors:\n");
    rknn_tensor_attr output_attrs[io_num.n_output];
    memset(output_attrs, 0, sizeof(output_attrs));
    for (int i = 0; i < io_num.n_output; i++)
    {
        output_attrs[i].index = i;
				/* RKNN_QUERY_OUTPUT_ATTR是输出Tensor 属性 */
        ret = rknn_query(ctx, RKNN_QUERY_OUTPUT_ATTR, &(output_attrs[i]), sizeof(rknn_tensor_attr));
        if (ret != RKNN_SUCC)
        {
            printf("rknn_query fail! ret=%d\n", ret);
            return -1;
        }
				/* 打印输出的Tensor 属性 */
        printRKNNTensor(&(output_attrs[i]));
    }

    /* 加载图片 */
    unsigned char *input_data = NULL;
    input_data = load_image(img_path, &input_attrs[0]);
    if (!input_data)
    {
        return -1;
    }

    /* 模型输入的图片数据 */
    rknn_input inputs[1];
    memset(inputs, 0, sizeof(inputs));
    inputs[0].index = 0;
    inputs[0].type = RKNN_TENSOR_UINT8;   /* RKNN_TENSOR_UINT8为3 */
		/* 输入图片数据的大小是224*224*3=150528 */
    inputs[0].size = input_attrs[0].size;
    inputs[0].fmt = RKNN_TENSOR_NHWC;
		/* 输入数据 Buffer 的指针 */
    inputs[0].buf = input_data;
		/* 设置模型的输入数据 */
    ret = rknn_inputs_set(ctx, io_num.n_input, inputs);
    if (ret < 0)
    {
        printf("rknn_input_set fail! ret=%d\n", ret);
        return -1;
    }

    // Run
    printf("rknn_run\n");
    ret = rknn_run(ctx, nullptr);/* 执行一次模型推理 */
    if (ret < 0)
    {
        printf("rknn_run fail! ret=%d\n", ret);
        return -1;
    }

    // Get Output
    rknn_output outputs[1];/* 模型的一个数据输出 */
    memset(outputs, 0, sizeof(outputs));
    outputs[0].want_float = 1;/* 将输出数据转为 float 类型输出 */
		/* 获取模型推理的输出数据 */
    ret = rknn_outputs_get(ctx, 1, outputs, NULL);
    if (ret < 0)
    {
        printf("rknn_outputs_get fail! ret=%d\n", ret);
        return -1;
    }

    // Post Process
    for (int i = 0; i < io_num.n_output; i++)
    {
        uint32_t MaxClass[5];/* 打印top5的类别，打印的只有5类 */
        float fMaxProb[5];	 /* top5的概率，即前5类的概率 */
        float *buffer = (float *)outputs[i].buf;/* 输出数据 Buffer 的指针 */
				/* 输出数据 Buffer 所占内存大小除以4的结果，因为前面设置了loat 类型输出（want_float=1），
				也就是由uint8转换成转换成 float32，即除以4 */
        uint32_t sz = outputs[i].size / 4;
				/* 输出数据 Buffer 的指针、前5类的概率、前5类、大小、类的个数是5 */
        rknn_GetTop(buffer, fMaxProb, MaxClass, sz, 5);
				/* 以下print的代码是自己加的
				打印：
						buffer=-1367176348
						sz= 1001
				*/
        printf("buffer=%8.6f \n",&buffer);
				printf("sz= %3d \n",sz);
				
        printf(" --- Top5 ---\n");
				/* 一个模型的话，i就等于1 */
        for (int i = 0; i < 5; i++)
        {
						/* 前5类，前5类的概率 */
            printf("%3d: %8.6f\n", MaxClass[i], fMaxProb[i]);
        }
    }

    // Release rknn_outputs
    rknn_outputs_release(ctx, 1, outputs);/* 释放 rknn_output 对象 */

    // Release
    if (ctx >= 0)
    {
        rknn_destroy(ctx);/* 销毁 rknn_context 对象及其相关资源 */
    }
    if (model)
    {
        free(model);/* 释放模型 */
    }

    if (input_data)
    {
        stbi_image_free(input_data);/* 释放图片 */
    }

    return 0;
}