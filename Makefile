ROOT=$(PWD)
export ROOT
CXX=g++

sources.d:
	tools/enumeratesources

include sources.d
DEPS=$(SOURCES:.cpp=.d)

%.d: %.cpp
	$(CXX) -MF"$@" -MG -MM -MP -MT"$@" -MT"$(<:.cpp=.o)" "$<"

include $(DEPS)

COMMON=$(ROOT)/src/common/ns.h $(ROOT)/src/common/types.h
CXXFLAGS=-I./src -I$(ROOT)/src/common -I$(ROOT) -ggdb

#synergi: main.o osc/oscillator.o osc/puresine.o buf/circularbuffer.o osc/silence.o
#	$(CXX) $(CXXFLAGS) main.cpp osc/oscillator.o osc/puresine.o osc/silence.o buf/circularbuffer.o -o synergi -lasound

#all: synergi

#clean:
#	rm -f synergi test src/*.o src/osc/*.o src/buf/*.o src/tst/*.o src/eng/*.o src/*.d *.d

