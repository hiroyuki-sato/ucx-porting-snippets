
.SUFFIXES: .cc .lo .la

LIBTOOL=/usr/local/bin/glibtool
GTEST_BASE=$(CURDIR)
BUILD_DIR=$(GTEST_BASE)/build
VPATH=src:build
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

GTEST_SRCS=gtest-all.cc        \
           gtest-death-test.cc \
           gtest-filepath.cc   \
           gtest-matchers.cc   \
           gtest-port.cc       \
           gtest-printers.cc   \
           gtest-test-part.cc  \
           gtest-typed-test.cc \
           gtest.cc            \
           gtest_main.cc

#GTEST_OBJ=$(addprefix , $(GTEST_SRCS:.cc=.lo))
GTEST_OBJ=$(GTEST_SRCS:.cc=.lo)
BUILD_GTEST_OBJ=$(addprefix build/,$(GTEST_OBJ))

.cc.lo:
	$(LIBTOOL) --mode=compile --tag=CXX $(CXX) $(CFLAGS) -c $< -o $(BUILD_DIR)/$@

all: libgtest.la

libgtest.la: $(GTEST_OBJ)
	$(LIBTOOL) --mode=link --tag=CXX $(CXX) -o libgtest.la $(BUILD_GTEST_OBJ)

clean:
	@/bin/rm -rf build/*.{o,lo} build/.libs libgtest.la .libs
