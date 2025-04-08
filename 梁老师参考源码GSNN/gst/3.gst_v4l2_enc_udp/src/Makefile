SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
GST_VER := 0.1
TARGET  := gst_v4l2_enc_udp
DEFINES := 
INCLUDE :=
CFLAGS  += -g -Wall -O3 $(DEFINES) $(INCLUDE) `pkg-config gstreamer-1.0 --cflags` `pkg-config glib-2.0 --cflags`
LIBS    += `pkg-config gstreamer-1.0 --libs` `pkg-config gstreamer-app-1.0 --libs` -lpthread
LDFLAGS :=
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H
  
.PHONY : everything objs clean distclean rebuild
  
all : $(TARGET)
  
objs : $(OBJS)
  
rebuild: distclean all
                
clean :
	rm -rf *~
	rm -rf *.o
    
distclean : clean
	rm -rf $(TARGET)
  
$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
