PWD:= .

CC ?= $(CROSS_COMPILE)gcc
AR ?= $(CROSS_COMPILE)ar

TARGET=	libmcflib.a

CFLAGS= -I$(PWD) -W -Wall -Wshadow -Wstrict-prototypes

SOURCES=dprc.c \
	dpaiop.c \
	dpdcei.c \
	dpdmai.c \
	dpmac.c \
	dpmcp.c \
	dpbp.c \
	dpio.c \
	dpni.c \
	dpsw.c \
	dpci.c \
	dpcon.c \
	dpseci.c \
	dpmng.c \
	dpdmux.c \
	mc_sys.c

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
