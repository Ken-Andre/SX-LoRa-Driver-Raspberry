# Makefile
PYTHONVER=python3.11
LIBNAME=loralib.so

all: loralib

loralib: SX1278.o SX1278_hw.o
	gcc -shared -o $(LIBNAME) -fPIC SX1278.o SX1278_hw.o -I/usr/include/$(PYTHONVER) -I/usr/local/include -L/usr/local/lib -lwiringPi

SX1278.o: SX1278.c
	gcc -fPIC -c SX1278.c -I/usr/include/$(PYTHONVER) -I/usr/local/include

SX1278_hw.o: SX1278_hw.c
	gcc -fPIC -c SX1278_hw.c -I/usr/include/$(PYTHONVER) -I/usr/local/include

lib: loralib

clean:
	rm -f *.o *.so
