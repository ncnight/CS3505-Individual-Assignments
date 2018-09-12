
CARDIR = carlib

car2: main.o
	g++ -o car main.o -L $(CARDIR)/lib -lcar

main.o: main.cpp
		g++ -c main.cpp -I $(CARDIR)/include
