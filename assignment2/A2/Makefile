CC = g++
CFLAGS = -Wall
INCLUDE = ../libharu/include
LIBHARU = ../libharu/src

spiralPDF: HaruPDF.o Spiral.o spiralPDF.cpp
	$(CC) $(CFLAGS) -L $(LIBHARU) -I $(INCLUDE) -o spiralPDF spiralPDF.cpp HaruPDF.o Spiral.o -lhpdfs

HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c HaruPDF.cpp

Spiral.o: Spiral.h Spiral.cpp
	$(CC) $(CFLAGS) -c Spiral.cpp

clean:
	rm -f *.o *.a spiralPDF.pdf spiralPDF

test: spiralPDF
	./spiralPDF "This is a sample text that should go in a spiral in a pdf. I love C++. This will be the test string that hopefully looks very pretty. It can go forever!!"
