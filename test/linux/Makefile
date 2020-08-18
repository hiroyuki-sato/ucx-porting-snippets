SRC=epoll_usage_test.cc \
    main.cc
OBJ=$(SRC:.cc=.o)
CFLAGS=-I$(CURDIR)/../../src -I$(CURDIR)/../gtest/include
LDFLAGS=-L$(CURDIR)/../../src -lsnippets -L$(CURDIR)/../gtest -lgtest -lpthread

.cc.o:
	$(CXX) -std=c++11 $< -c -o $@ $(CFLAGS)

all: gtest

gtest: $(OBJ)
	libtool --mode=link --tag=CXX $(CXX) -std=c++11 $(OBJ) -o $@ $(LDFLAGS)

clean:
	/bin/rm -rf *.o gtest

test: gtest
	./gtest
	
