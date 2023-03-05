#
# Makefile
# ghost, 2023-03-05 11:54
#

IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR) -g

ODIR=obj

LIBS=

_OBJ = main.o parser.o log.o plot.o
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: clean

all: main.exe
	@echo "Makefile needs your attention"

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main.exe: $(_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o
# vim:ft=make
#
format:
	clang-format -i *.c *.h
