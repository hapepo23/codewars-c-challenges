CC      = gcc
# CFLAGS  = -std=c18 -Wall -Wextra -O0 -g
CFLAGS  = -std=c18 -Wall -Wextra -O2
LDLIBS  = -lm
TARGETS = $(patsubst %_main.c,%,$(wildcard *_main.c))

.PHONY: all clean reformat run vrun

all: $(TARGETS)

%: %.c %_main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(TARGETS)

reformat:
	clang-format --style=Chromium -i *.c

run:
	./`zenity --title="Execute Program" --height 600 --list --text="Choose Executable" --column=Executable $(TARGETS)`

vrun:
	valgrind --leak-check=full --show-error-list=yes ./`zenity --title="Valgrind Program" --height 600 --list --text="Choose Executable" --column=Executable $(TARGETS)`
