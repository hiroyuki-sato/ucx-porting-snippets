GTEST_BASE=$(CURDIR)

INCLUDES=-I$(GTEST_BASE)/include -I$(GTEST_BASE)/src -I$(GTEST_BASE)
CPPOPTS=-Wall \
        -Wshadow \
        -Werror  \
        -Wconversion \
        -DGTEST_HAS_PTHREAD=1 \
        -fexceptions \
        -W -Wpointer-arith \
        -Wreturn-type \
        -Wcast-qual \
        -Wwrite-strings \
        -Wswitch \
        -Wunused-parameter \
        -Wcast-align \
        -Wchar-subscripts \
        -Winline \
        -Wredundant-decls \
        -std=c++11 

CFLAGS=$(INCLUDES) $(CPPOPTS)

GTEST_SRCS=src/gtest-all.cc        \
           src/gtest-death-test.cc \
           src/gtest-filepath.cc   \
           src/gtest-matchers.cc   \
           src/gtest-port.cc       \
           src/gtest-printers.cc   \
           src/gtest-test-part.cc  \
           src/gtest-typed-test.cc \
           src/gtest.cc            \
           src/gtest_main.cc       

GTEST_OBJ=src/gtest-all.o        \
          src/gtest-death-test.o \
          src/gtest-filepath.o   \
          src/gtest-matchers.o   \
          src/gtest-port.o       \
          src/gtest-printers.o   \
          src/gtest-test-part.o  \
          src/gtest-typed-test.o \
          src/gtest.o            \
          src/gtest_main.o       

.cc.o: $(GTEST_SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(GTEST_OBJ) 


clean:
	@/bin/rm -rf src/*.o
