top_builddir=$(PWD)
KERNEL_PATH ?=
$(info "KERNEL_PATH=$(KERNEL_PATH)")

DESTDIR ?=
$(info "DESTDIR=$(DESTDIR)")

CROSS_COMPILE ?=
$(info "CROSS_COMPILE=$(CROSS_COMPILE)")

ARCH ?= aarch64
$(info "ARCH=$(ARCH)")

CC ?= $(CROSS_COMPILE)gcc

# PATHS
SRCDIR	= src
SRCS	= $(SRCDIR)/aiop_tool.c $(SRCDIR)/aiop_cmd.c $(SRCDIR)/aiop_tool_dummy.c $(SRCDIR)/aiop_lib.c $(SRCDIR)/aiop_logger.c
BINNAME = aiop_tool
VFIODIR	= src/vfio
MCDIR	= flib/mc
BINDIR	= bin


# FLAGS
CFLAGS = -Wall
CFLAGS += -I$(top_builddir)/include
CFLAGS += -I$(top_builddir)/src
CFLAGS += -I$(top_builddir)/src/vfio
CFLAGS += -I$(top_builddir)/flib/mc
CFLAGS += -I$(KERNEL_PATH)

#Flags passed on make command line
CFLAGS += $(CMDFLAGS)

# TARGETS
EXECS	= $(SRCS:%.c=%)
OBJS	= $(SRCS:%.c=%.o)
DEPS	= $(SRCS:%.c=%.d)

LFLAGS	+= $(VFIODIR)/libvfio.a
LFLAGS	+= $(MCDIR)/libmcflib.a

# RULES
all: $(BINNAME)

execs:   $(EXECS)

mcflib:
	$(MAKE) -C $(MCDIR) all

vfio:
	$(MAKE) -C $(VFIODIR) all

$(BINNAME): $(OBJS) mcflib vfio
	@mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $(CFLAGS) $(OBJS) $(LFLAGS)

install: all
	@mkdir -p $(DESTDIR)/usr/bin
	cp -ar $(BINDIR)/$(BINNAME) $(DESTDIR)/usr/bin/

.PHONY: vfio mcflib $(BINNAME) install clean

clean:
	rm -rf $(EXECS) $(OBJS) $(DEPS) $(BINDIR) *.d *.a
	@for subdir in $(VFIODIR) $(MCDIR); do \
	     $(MAKE) -C $$subdir clean; \
	done
