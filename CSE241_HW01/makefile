all: main

main: main.o source.o
	g++ main.o source.o -o exe

source.o: source.cpp
	g++ -c source.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o main
