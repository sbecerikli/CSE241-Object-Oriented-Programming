#ifndef BIGRAMMAP_H
#define BIGRAMMAP_H


#include "Bigram.h"

using std::istringstream;
using std::stringstream;

namespace SB_Bigram{


	template<class T>
	class BigramMap : public Bigram<T>
	{
	public:
        BigramMap(int datatype) {totalNumGramsX = 0, numOfGramsX = 0;}
        BigramMap() : Bigram<T>() {}
        ~BigramMap() { Grams.clear(); }
		BigramMap(const BigramMap<T>& other); //copy constructor
		BigramMap<T>& operator=(const BigramMap<T>& other); //assignment operator
		void print(ostream& o) const;

		//virtual
		virtual int readFile(string filename) throw(exception);
        virtual int numGrams() throw(exception);
		virtual int numOfGrams(T first, T second) throw(exception);
		virtual pair<T, T> maxGrams() throw(exception);

        inline void setTotalNumGrams(const int n) { totalNumGramsX = n; }
        inline int getTotalNumgrams() const { return totalNumGramsX;}
        inline void setNumOfGrams(const int n) { numOfGramsX = n; }
        inline int getNumOfGrams() const { return numOfGramsX; }

		inline void setGrams(const map<pair<T, T>, int> other) { Grams = other; }
		inline map<pair<T, T>, int> getGrams() { return Grams; }

		void printGrams();

	private:
        int totalNumGramsX;
        int numOfGramsX;

		map<pair<T, T>, int> Grams;
				
	};
}

#endif
