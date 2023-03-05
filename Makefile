#
# Makefile
# ghost, 2023-03-05 11:54
#

IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj

LIBS=

_OBJ = main.o
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: clean

all:
	@echo "Makefile needs your attention"

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main.exe: $(_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o
# vim:ft=make
#
