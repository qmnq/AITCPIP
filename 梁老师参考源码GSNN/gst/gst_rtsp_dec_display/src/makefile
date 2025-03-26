CFLAGS  += -g -Wall -O3 `pkg-config --cflags gstreamer-1.0`
LIBS    += 
LDFLAGS := `pkg-config gstreamer-1.0 --libs`
CXXFLAGS:= $(CFLAGS)
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
TARGET  := gst_rtsp_dec_display

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

