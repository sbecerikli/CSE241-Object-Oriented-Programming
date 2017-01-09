//
// Created by sbecerikli on 12/29/16.
//

#include "BigramDyn.h"


namespace SB_Bigram{

    template <class T>
    BigramDyn<T>::BigramDyn(const BigramDyn<T> &other) { //copyconsstructor
        delete[] Grams;
        delete[] GramsCount;
        Grams = new pair<T, T>[other.getSize()];
        GramsCount = new int [other.getSize()];
        for (int i = 0; i < other.getSize(); ++i) {
            Grams[i] = other.Grams[i];
            GramsCount[i] = other.GramsCount[i];
        }
        setSize(other.getSize());
        setCapacity(other.getCapactiy());
    }
    template <class T>
    BigramDyn<T>& BigramDyn<T>::operator=(const BigramDyn<T> &other) { // assigmnment

        if(this != &other){
            delete[] Grams;
            delete[] GramsCount;

            setCapacity(other.getCapactiy());
            setSize(other.getSize());
            Grams = new pair<T, T>[other.getSize()];
            GramsCount = new int [other.getSize()];
            for (int i = 0; i < other.getSize(); ++i) {
                Grams[i] = other.Grams[i];
                GramsCount[i] = other.GramsCount[i];
            }
            return *this;

        }
        return *this;
    }


    template <class T>
    int BigramDyn<T>::readFile(string filename) throw(exception){

        string line;
        ifstream MyFile(filename.c_str());
        cout << "filename : " << filename << endl;
        if (MyFile.is_open()) {
            getline(MyFile, line);
    
            istringstream WhiteSpace(line);
            string SubStr;
            T v1, v2;
            WhiteSpace >> SubStr;
            int index;
            while(WhiteSpace.good()) {
                string tempSubStr = SubStr;
                WhiteSpace >> SubStr;
                stringstream convert1(SubStr);
                stringstream convert2(tempSubStr);
                convert1 >> v1;
                convert2 >> v2;
                
                if (search(pair<T, T>(v2, v1), &index)) {
                    
                    GramsCount[index] += 1;
                }
                else{
                    insert(pair<T, T>(v2, v1), 1);    
                }
                
                //setSize(getSize() + 1);
            }
            MyFile.close();
            setTotalNumGrams(getSize());

        }
        else
        {
            exception e;
            e.cantFind = true;
            throw e;
        }
        return  getTotalNumgrams();
    }

    template <class T>
    bool BigramDyn<T>::search(pair<T, T> p, int* index){
        for (int i = 0; i < getSize(); ++i) {
            if(Grams[i].first == p.first && Grams[i].second == p.second){
                
                *index = i;
                return true;
            }
        }
        return false;
    }
    template <class T>
    void BigramDyn<T>::insert(pair<T, T> p, int count){
        if(getSize() == getCapactiy()){
            pair<T, T>* tempGrams = new pair<T, T>[getCapactiy() + 10];
            int* tempGramsCount = new int[getCapactiy() + 10];
            setCapacity(getCapactiy() + 10);
            for (int i = 0; i < getSize(); ++i) {
                tempGrams[i] = Grams[i];
                tempGramsCount[i] = GramsCount[i];
            }
            tempGrams[getSize()] = p;
            tempGramsCount[getSize()] = count;
            setSize(getSize() + 1);
        }
        else{
            Grams[getSize()] = p;
            GramsCount[getSize()] = count;
            setSize(getSize() + 1);
        }
    }

    template <class T>
    int BigramDyn<T>::numGrams() throw(exception){

        return getTotalNumgrams();
    }
    template <class T>
    int BigramDyn<T>::numOfGrams(T first, T second) throw(exception){

        for (int i = 0; i < getSize(); ++i) {
            if(Grams[i].first == first && Grams[i].second == second){
                return GramsCount[i];
            }
        }


    }
    template<class T>
    pair<T, T> BigramDyn<T>::maxGrams() throw(exception){
        int counts[getSize()];
        for (int i = 0; i < getSize(); ++i) {
            counts[i] = GramsCount[i];
        }
        int temp = 0;
        int index;
        for(int i = 0 ; i < getSize(); ++i)
        {
            if(counts[i]>temp){
               temp = counts[i];
               index = i; 
            }
        }
        return Grams[index];
    }

    template<class T>
     void BigramDyn<T>::print(ostream& out) const{
       sort(Grams, + Grams+getSize());
       for(int i = 0; i < getSize(); ++i){
            out << Grams[i].first << ", " << Grams[i].second << ": " << GramsCount[i] << endl ;
       }
    }

}
