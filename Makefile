ROOT=$(PWD)
export ROOT
CXX=g++
CXXFLAGS=-I./src -I/usr/include/cppunit -ggdb
LIBS=-lasound
SYNERGI_OBJS=src/main.o src/osc/wavetable.o src/osc/oscillator.o src/osc/puresine.o src/buf/circularbuffer.o src/osc/silence.o
TEST_MODULES=$(wildcard src/tst/*.cpp)
TEST_OBJS=$(TEST_MODULES:.cpp=.o)
TEST_TARGETS=src/buf/circularbuffer.o src/osc/wavetable.o

sources.d:
	tools/enumeratesources

include sources.d
DEPS=$(SOURCES:.cpp=.d)
include $(DEPS)

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MF"$@" -MT"$@" -MT"$(@:.d=.o)" -MM $<

synergi: $(SYNERGI_OBJS)
	$(CXX) $(CXXFLAGS) $(SYNERGI_OBJS) $(LIBS) -o $@

test: $(TEST_OBJS) $(TEST_TARGETS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) $(LIBS) $(TEST_TARGETS) -lcppunit -o $@

all: synergi test
	./test

clean:
	rm -f synergi test src/*.o src/osc/*.o src/buf/*.o src/tst/*.o src/eng/*.o src/*.d *.d src/osc/*.d src/buf/*.d src/tst/*.d

