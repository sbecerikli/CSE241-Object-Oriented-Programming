all: _mainTester

_mainTester:  _mainTester.o Register.o CPU.o CPUProgram.o Memory.o Computer.o CPUProgramDyn.o 
	g++  _mainTester.o Register.o CPU.o CPUProgram.o Memory.o Computer.o CPUProgramDyn.o -o exe

Register.o: Register.cpp
	g++ -c Register.cpp

CPU.o: CPU.cpp
	g++ -c CPU.cpp

CPUProgram.o: CPUProgram.cpp
	g++ -c CPUProgram.cpp

CPUProgramDyn.o: CPUProgramDyn.cpp
	g++ -c CPUProgramDyn.cpp

Memory.o: Memory.cpp
	g++ -c Memory.cpp

Computer.o: Computer.cpp
	g++ -c Computer.cpp

_mainTester.o: _mainTester.cpp
	g++ -c _mainTester.cpp

clean:
	rm *.o exe
