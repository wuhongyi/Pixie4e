# Jungo Connectivity Confidential. Copyright (c) 2018 Jungo Connectivity Ltd.  https://www.jungo.com

# TODO: Set WD_BASEDIR to the location of your WinDriver installation directory.
#       For example: WD_BASEDIR=/home/john/WinDriver

# Make sure that WD_BASEDIR points to the right place
ifeq ($(WD_BASEDIR),)
        WD_BASEDIR=../../../
endif

WD_BASEDIR:=$(wildcard $(WD_BASEDIR))

ifeq ($(wildcard $(WD_BASEDIR)/include/windrvr.h),)
        $(error Please edit the makefile and set the WD_BASEDIR variable \
        to point to the location of your WinDriver installation directory)
endif

# Comment/uncomment to enable/disable debugging code
# DEBUG = 1

ifeq ($(DEBUG),1)
    DEBFLAGS = -g -O -DDEBUG
else
    DEBFLAGS = -O2
endif

ifndef TARGET_CPU
	TARGET_CPU=$(shell uname -m | sed 's/i.86/i386/' | sed 's/arm.*/ARM/')
endif
ifeq ("$(TARGET_CPU)", "x86_64")
	CFLAGS += -DKERNEL_64BIT
	ifndef USER_BITS
		USER_BITS = 64
	endif
	CFLAGS += -m$(USER_BITS)
	LFLAGS += -m$(USER_BITS)
endif
ifeq ("$(TARGET_CPU)", "ARM")
	CFLAGS += -DARM
endif

CFLAGS += -DLINUX $(DEBFLAGS) -Wall -I$(WD_BASEDIR)/include -I$(WD_BASEDIR)
CFLAGS += -Dx86_64 -DWD_DRIVER_NAME_CHANGE -Wno-unused-result -Wno-write-strings
LFLAGS += -lwdapi1281
# Need also thread support for interrupt handling
LFLAGS += -lpthread

TARGET = basic_io
SRCS = ../basic_io.c

LD = gcc

OD = ./
OBJS = $(addsuffix .o, $(addprefix $(OD)/, $(basename $(notdir $(SRCS)))))


all : $(TARGET)

$(TARGET) : $(OBJS)
	$(LD) -o $@ $(OBJS) $(LFLAGS) $(ADDITIONAL_LIBS)

basic_io.o : ../basic_io.c
	$(CC) -c $(CFLAGS) -o $@ $<


clean :
	rm -f *~ core $(OBJS) $(TARGET) $(ARCH)

