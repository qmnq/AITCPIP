SDK_PATH = /home/tronlong/RK3568/rk356x_linux_release_v1.3.1_20221120
SYSROOT  += $(SDK_PATH)/buildroot/output/rockchip_rk3568/host/aarch64-buildroot-linux-gnu/sysroot

INCLUDES += -I./ -I$(SYSROOT)/usr/include/gstreamer-1.0 \
			    -I$(SYSROOT)/usr/include/glib-2.0 \
			    -I$(SYSROOT)/usr/lib/glib-2.0/include

CFLAGS  += -g -Wall -O3 -Wl,--sysroot=$(SYSROOT) $(INCLUDES)
LIBS    += -lpthread
LDFLAGS := `pkg-config gstreamer-1.0 --libs` -L$(SYSROOT)/usr/lib
CXXFLAGS:= $(CFLAGS)
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
TARGET  := gst_dec_display

.PHONY : clean distclean rebuild

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

rebuild: distclean all

clean :
	rm -rf *~
	rm -rf *.o

distclean : clean
	rm -rf $(TARGET)

