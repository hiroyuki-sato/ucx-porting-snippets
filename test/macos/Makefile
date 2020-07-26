LIBTOOL=/usr/local/bin/glibtool
SRC=hello.cc \
    hello2.cc \
    main.cc
OBJ=$(SRC:.cc=.o)

.cc.o:
	$(CXX) -std=c++11 $< -c -o $@ -I$(CURDIR)/../gtest/include

all: gtest

gtest: $(OBJ)
	glibtool --mode=link --tag=CXX $(CXX) -std=c++1 $(OBJ) -o $@ -L$(CURDIR)/../gtest -lgtest

clean:
	/bin/rm -rf *.o gtest

test: gtest
	./gtest
	
