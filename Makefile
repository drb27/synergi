ROOT=$(PWD)
export ROOT
include defs.mk

synergi: main.cpp osc/oscillator.o buf/audiobuffer.o
	@echo $(ROOT)
	$(CC) $(CFLAGS) main.cpp osc/oscillator.o buf/audiobuffer.o -o synergi -lasound

%.o: %.cpp

osc/oscillator.o : force_look
buf/audiobuffer.o : force_look

include rules.mk

all: synergi

clean:
	rm synergi

force_look :
	make -C osc
	make -C buf