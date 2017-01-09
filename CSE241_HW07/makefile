all: _mainTester

_mainTester:  _mainTester.o 
	g++  _mainTester.o  -o exe

BigramMap.o: BigramMap.cpp
	g++ -std=c++11 -c BigramMap.cpp

BigramDyn.o: BigramDyn.cpp
	g++ -std=c++11 -c BigramDyn.cpp


_mainTester.o: _mainTester.cpp
	g++ -std=c++11 -c _mainTester.cpp

clean:
	rm *.o exe
