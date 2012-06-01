ROOT=$(PWD)
export ROOT
COMMON=$(ROOT)/common/ns.h $(ROOT)/common/types.h
CFLAGS=-I. -I$(ROOT)/common -I$(ROOT)
CC=g++

synergi: main.cpp osc/oscillator.o buf/audiobuffer.o osc/silence.o
	@echo $(ROOT)
	$(CC) $(CFLAGS) main.cpp osc/oscillator.o osc/silence.o buf/audiobuffer.o -o synergi -lasound


%.o: %.cpp

%.o: %.cpp %.h $(COMMON)
	$(CC) $(CFLAGS) -c -o $@ $<


all: synergi

clean:
	rm -f synergi *.o osc/*.o buf/*.o

