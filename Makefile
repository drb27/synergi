COMMON=ns.h
CFLAGS=
CC=g++
synergi: main.cpp oscillator.o
	$(CC) $(CFLAGS) main.cpp oscillator.cpp -o synergi -lasound

%.o: %.cpp %.h $(COMMON)
	$(CC) $(CFLAGS) -c -o $@ $<
all: synergi

clean:
	rm synergi oscillator.o