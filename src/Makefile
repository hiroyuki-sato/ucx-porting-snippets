.SUFFIXES: .cc .lo .la

LIBTOOL=/usr/local/bin/glibtool

SRC=link_speed.c
OBJ=$(SRC:.c=.lo)
CFLAGS=-I$(CURDIR)

.c.lo:
	$(LIBTOOL) --mode=compile --tag=CC $(CC) -c $(CFLAGS) $< -o $@

libsnippets.la: $(OBJ)
	$(LIBTOOL) --mode=link --tag=CC $(CC) -o $@ $(OBJ)

all: libsnippets.la


clean:
	rm -rf libsnippets.la $(OBJ) *.o .libs

