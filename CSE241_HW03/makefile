all: main

main: main.o Register.o CPU.o CPUProgram.o Memory.o Computer.o
	g++ main.o Register.o CPU.o CPUProgram.o Memory.o Computer.o -o exe

Register.o: Register.cpp
	g++ -c Register.cpp

CPU.o: CPU.cpp
	g++ -c CPU.cpp

CPUProgram.o: CPUProgram.cpp
	g++ -c CPUProgram.cpp

Memory.o: Memory.cpp
	g++ -c Memory.cpp

Computer.o: Computer.cpp
	g++ -c Computer.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o exe
