SDK_ROOT_PATH=/home/tronlong/RK3568/rk356x_linux_release_v1.3.1_20221120
CROSS_COMPILE=$(SDK_ROOT_PATH)/buildroot/output/rockchip_rk3568/host/bin/aarch64-buildroot-linux-gnu-
SYSROOT=$(SDK_ROOT_PATH)/buildroot/output/rockchip_rk3568/staging

CC	:= $(CROSS_COMPILE)gcc --sysroot=$(SYSROOT)
CFLAGS	= -O2 -W -Wall -std=gnu99 -I$(SYSROOT)/usr/include/libdrm
LDFLAGS	= -L$(SYSROOT)/usr/lib
LIBS	= -lrt -ldrm

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: v4l2_capture

v4l2_capture: main.o util.o drm.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	-rm -f *.o
	-rm -f v4l2_capture
