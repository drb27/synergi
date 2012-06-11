ROOT=$(PWD)
export ROOT
COMMON=$(ROOT)/common/ns.h $(ROOT)/common/types.h $(ROOT)/eng/midi.h
CFLAGS=-I. -I$(ROOT)/common -I$(ROOT) -ggdb
TESTDEPS=tst/main.cpp tst/CircularBufferTest.cpp tst/CircularBufferTest.h tst/WavetableTest.cpp tst/WavetableTest.h
TESTED=buf/circularbuffer.cpp osc/oscillator.cpp osc/wavetable.cpp
CC=g++

synergi: main.cpp osc/oscillator.o osc/puresine.o buf/circularbuffer.o osc/silence.o osc/wavetable.o
	$(CC) $(CFLAGS) main.cpp osc/oscillator.o osc/puresine.o osc/silence.o buf/circularbuffer.o osc/wavetable.o -o synergi -lasound

test: $(TESTDEPS) $(TESTED) $(COMMON)
	$(CC) $(CFLAGS) -I/usr/include/cppunit $(TESTED) tst/main.cpp tst/WavetableTest.cpp tst/CircularBufferTest.cpp -o test -lasound -lcppunit

%.o: %.cpp

%.o: %.cpp %.h $(COMMON)
	$(CC) $(CFLAGS) -c -o $@ $<

all: synergi test
	./test


clean:
	rm -f synergi test *.o osc/*.o buf/*.o tst/*.o eng/*.o

