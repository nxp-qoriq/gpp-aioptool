top_srcdir=./
top_builddir=$(top_srcdir)
LIB   	= $(top_builddir)/lib
SDKDIR	= /home/shreyansh/build/sdk-devel/ls2-linux/

# Set tool names
CROSS_COMPILE=/opt/freescale/tools/gcc-linaro/bin/aarch64-linux-gnu-
#CROSS_COMPILE=/usr/bin/
ARCH = aarch64

CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld
CPP = $(CROSS_COMPILE)cpp
NM = $(CROSS_COMPILE)nm
STRIP = $(CROSS_COMPILE)strip
OBJCOPY = $(CROSS_COMPILE)objcopy
AR = $(CROSS_COMPILE)ar
RM = rm

# PATHS
SRCDIR	= src
SRCS	= $(SRCDIR)/aiop_tool.c $(SRCDIR)/aiop_cmd.c $(SRCDIR)/aiop_tool_dummy.c $(SRCDIR)/aiop_lib.c $(SRCDIR)/aiop_logger.c
BINNAME = aiop_tool
VFIODIR	= src/vfio
MCDIR	= flib/mc
OBJDIR	= objs
BINDIR	= bin


# FLAGS
#CFLAGS = -g -Wall -v
CFLAGS = -Wall
CFLAGS += -I$(top_builddir)/include
CFLAGS += -I$(top_builddir)/src
CFLAGS += -I$(top_builddir)/src/vfio
CFLAGS += -I$(top_builddir)/flib/mc
CFLAGS += -I$(SDKDIR)

LFLAGS +=

#Flags passed on make command line
CFLAGS += $(CMDFLAGS)

# TARGETS
EXECS	= $(SRCS:%.c=%)
OBJS	= $(SRCS:%.c=%.o)
DEPS	= $(SRCS:%.c=%.d)

LFLAGS	+= $(VFIODIR)/libvfio.a
LFLAGS	+= $(MCDIR)/libmcflib.a

# RULES

all: mcflib vfio $(BINNAME)

execs:   $(EXECS)

mcflib:
	cd $(MCDIR); $(MAKE); cd -

vfio:
	cd $(VFIODIR); $(MAKE); cd -

$(BINNAME): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $(CFLAGS) $(OBJS) $(LFLAGS)

install: all

.PHONY: vfio mcflib $(BINNAME) install

clean:
	$(RM) -f $(EXECS) $(OBJS) $(DEPS) $(BINDIR)/$(BINNAME) *.d *.a
	cd $(VFIODIR); make clean; cd -
	cd $(MCDIR); make clean; cd -
