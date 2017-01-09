//
// Created by sbecerikli on 12/29/16.
//

#ifndef CSE241_HW07_BIGRAMDYN_H
#define CSE241_HW07_BIGRAMDYN_H

#include "Bigram.h"

using std::istringstream;
using std::stringstream;

namespace SB_Bigram{

    template<class T>
    class BigramDyn : public Bigram<T>{

    public:
        BigramDyn(int datatype) {totalNumGramsX = 0, numOfGramsX = 0, size = 0, capacity = 50, GramsCount = new int[50], Grams = new pair<T, T>[50];}
        BigramDyn() : Bigram<T>() {}
        ~BigramDyn() { delete[] Grams; delete[] GramsCount;}
        BigramDyn(const BigramDyn<T>& other); //copy constructor
        BigramDyn<T>& operator=(const BigramDyn<T>& other); //assignment operator
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


        inline void setCapacity(const int c){capacity = c;}
        inline int getCapactiy() const {return capacity;}
        inline void setSize(const int s) {size = s;}
        inline int getSize() const {return size;}

        //inline void setGrams(const map<pair<T, T>, int> other) { Grams = other; }
        //inline map<pair<T, T>, int> getGrams() { return Grams; }

        void printGrams();
        bool search(pair<T, T> value, int* index);
        void insert(pair<T, T> value, int count);

    private:
        int totalNumGramsX;
        int numOfGramsX;
        int size;
        int capacity;
        pair<T, T>* Grams;
        int* GramsCount;
    };




}




#endif //CSE241_HW07_BIGRAMDYN_H
