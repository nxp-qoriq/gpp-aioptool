PWD:= .

CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar

TARGET=	libvfio.a

CFLAGS= -I$(PWD) -W -Wall -Wshadow -Wstrict-prototypes
CFLAGS+= -I$(KERNEL_PATH)
CFLAGS+= -I../../$(PWD)/include

ifdef SYSROOT
  CFLAGS += --sysroot=$(SYSROOT)
endif

SOURCES=fsl_vfio.c

OBJECTS=$(SOURCES:.c=.o)

all:     $(TARGET)
	 @echo $(TARGET) has been created

$(TARGET):$(OBJECTS)
	 @echo "Creating" $@
	 $(AR) ruv $@ $(OBJECTS)
	 ranlib $@

.c.o:
	 @echo "Compiling" $*.c
	 $(CC) $(CFLAGS) -c $< -o $@ 2>/dev/null

clean:
	@echo "Cleaning up..."
	rm -f *.o *.a
