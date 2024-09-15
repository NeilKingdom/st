# st - simple terminal
# See LICENSE file for copyright and license details.

include config.mk

INC_DIR := include
SRC_DIR := src
OBJ_DIR := obj

SRCS := $(wildcard $(SRC_DIR)/*.c)
DEPS := $(wildcard $(INC_DIR)/*.h)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: options st

options:
	@echo st build options:
	@echo "CCFLAGS  = $(CCFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $< -c -o $@ $(CCFLAGS) $(LDFLAGS)

st: $(OBJS)
	$(CC) $^ -o $@ $(CCFLAGS) $(LDFLAGS)

clean:
	rm -f st $(OBJ_DIR)/*

dist: clean
	mkdir -p st-$(VERSION)
	cp -r LICENSE Makefile README.md config.mk \
		$(SRC_DIR) $(INC_DIR) $(OBJ_DIR) res st-$(VERSION)
	tar -cf st-$(VERSION).tar st-$(VERSION)
	gzip st-$(VERSION).tar
	rm -rf st-$(VERSION)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f st $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/st
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < res/doc/st.1 > $(DESTDIR)$(MANPREFIX)/man1/st.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/st.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/st $(DESTDIR)$(MANPREFIX)/man1/st.1

.PHONY: all options clean dist install uninstall
