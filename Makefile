ROOT=$(PWD)
export ROOT
CXX=g++
CXXFLAGS=-I./src -I/usr/include/cppunit -ggdb
CXXFLAGS_EXTRA=
LIBS=-lasound -lgcov
SYNERGI_OBJS=src/eng/source.o src/buf/rawbuffer.o src/eng/midilistener.o src/eng/component.o src/dsp/tremolo.o src/dsp/unitygain.o src/eng/inlet.o src/eng/outlet.o src/eng/transform.o src/eng/sink.o src/dsp/dsp.o src/main.o src/osc/wavetable.o src/osc/oscillator.o src/osc/puresine.o src/buf/circularbuffer.o src/osc/silence.o
TEST_MODULES=$(wildcard src/tst/*.cpp)
TEST_OBJS=$(TEST_MODULES:.cpp=.o)
TEST_TARGETS=src/buf/circularbuffer.o src/buf/rawbuffer.o src/osc/wavetable.o src/osc/oscillator.o src/eng/outlet.o src/eng/component.o src/eng/source.o src/dsp/dsp.o src/eng/inlet.o src/eng/midilistener.o src/osc/puresine.o

ifdef COVERAGE
LIBS += -lgcov
CXXFLAGS += -fprofile-arcs -ftest-coverage -O0 -fno-inline
endif

sources.d:
	tools/enumeratesources

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_EXTRA) -c -o $@ $<

include sources.d
DEPS=$(SOURCES:.cpp=.d)
include $(DEPS)

%.d: %.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_EXTRA) -MF"$@" -MT"$@" -MT"$(@:.d=.o)" -MM $<

synergi: $(SYNERGI_OBJS)
	$(CXX) $(CXXFLAGS) $(SYNERGI_OBJS) $(LIBS) -o $@

test: $(TEST_OBJS) $(TEST_TARGETS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) $(LIBS) $(TEST_TARGETS) -lcppunit -o $@

all: synergi test
	./test

coverage: test
	./test
	cd cov; lcov --capture --output-file app.info -b /home/drb/workspace/synergi --directory /home/drb/workspace/synergi/src
	cd cov; lcov --remove app.info "/usr*" -o app.info
	cd cov; genhtml app.info
	xdg-open cov/index.html &
clean:
#rm -f -r synergi test cov/* src/*.o src/osc/*.o src/buf/*.o src/tst/*.o src/eng/*.o src/*.d *.d src/osc/*.d src/dsp/*.o src/dsp/*.d  src/buf/*.d src/tst/*.d
	rm -f synergi test
	rm -f -r cov/*
	find . -type f -name "*.o" -exec rm {} \;
	find . -type f -name "*.d" -exec rm {} \;
	find . -type f -name "*.gcda" -exec rm {} \;
	find . -type f -name "*.gcno" -exec rm {} \;
