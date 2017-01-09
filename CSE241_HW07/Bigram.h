#ifndef BIGRAM_H
#define BIGRAM_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using std::pair;
using std::vector;
using std::map;
using std::multimap;
using std::ifstream;

namespace SB_Bigram
{
	template <class T>
	class Bigram
	{
	public:
        //Bigram();
        //~Bigram();

		virtual int readFile(string filename) = 0;
		virtual int numGrams() = 0;
		virtual int numOfGrams(T first, T second) = 0;
		
		virtual void print(ostream& out) const {}
		friend ostream& operator<<(ostream& out, const Bigram& b){
			b.print(out); 
			return out;
		}
		virtual pair<T, T> maxGrams() = 0;
	};





class exception
	{
	public:
    exception() : cantFind(false), outOfRange(false), badAlloc(false) { /* empty */ }

		bool cantFind;
		bool outOfRange;
		bool badAlloc;
		bool what(){
			if(cantFind){
				cout << "Can't find" << endl;
			}
			if(outOfRange){
				cout << "Out of range" << endl;
			}
			if(badAlloc){
				cout << "Bad alloc" << endl;
			}
		}
	};

}

#endif
