# st version
VERSION = 0.9

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# Freetype
FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2

# Includes and libs
INCS = -I$(X11INC) -I$(FREETYPEINC) -Iinclude
LIBS = -L$(X11LIB) $(FREETYPELIBS) -lm -lrt -lX11 -lutil -lXrender

# Flags
CPPFLAGS = -DVERSION=\"$(VERSION)\" -D_XOPEN_SOURCE=600
CCFLAGS = -std=c99 -Wall -Wno-deprecated-declarations -Os $(INCS) $(CPPFLAGS)
LDFLAGS = $(LIBS)

CC = gcc
