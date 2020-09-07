CC=gcc
SRC=foo.c bar.c
LIBTOOL=/usr/local/bin/glibtool
OBJ=$(SRC:.c=.lo)
CFLAGS=-I$(CURDIR) -fPIC
LDFLAGS=-dynamiclib -shared -Wl,-undefined -Wl,error \
        -Wl,-install_name libfoo.dylib \
        -current_version 1.0

OBJ=$(SRC:.c=.lo)
#.c.lo: $(SRC)
#	$(LIBTOOL) --mode=compile --tag=CC $(CC) -c $(CFLAGS) $< -o $@

#libfoo.la: foo.lo
#	$(LIBTOOL) --mode=link --tag=CC $(CC) $(LDFLAGS) -o $@ $<
#
#foo.lo: foo.c
#	$(LIBTOOL) --mode=compile --tag=CC $(CC) -c $(CFLAGS) $< -o $@

libfoo.dylib: foo.o
	$(CC) -Wl,-undefined -Wl,dynamic_lookup -dynamiclib \
              -compatibility_version 1 \
              -install_name /usr/lib/libhoge.0.dylib \
              -current_version 1.0 -Wl,-single_module $<  -o $@

# Without insatll_name build succeed with two-level namespace
#	$(CC) -Wl,-undefined -Wl,dynamic_lookup -dynamiclib \
#              -compatibility_version 1 \
#              -current_version 1.0 -Wl,-single_module $<  -o $@

foo.o: foo.c
#	$(CC) -MD -MP -MF hoge.tpo -o $@ -c $<
	$(CC) -o $@ -c $<

clean:
	/bin/rm -rf *.lo lib* *.o
