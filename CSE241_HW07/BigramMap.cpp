#include "BigramMap.h"




namespace SB_Bigram{

	template<class T>
    BigramMap<T>::BigramMap(const BigramMap<T>& other){
        this->totalNumGramsX = other.totalNumGramsX;
        this->numOfGramsX = other.numOfGramsX;
        this->Grams = other.Grams;
	}

	template<class T>
    BigramMap<T>& BigramMap<T>::operator=(const BigramMap<T>& other){
        this->totalNumGramsX = other.totalNumGramsX;
        this->numOfGramsX = other.numOfGramsX;
        this->Grams = other.Grams;
		return *this;
	}

	template<class T>
    int BigramMap<T>::readFile(string filename) throw(exception){
		string line;
        ifstream MyFile(filename.c_str());
        cout << "filename : " << filename << endl;
		if (MyFile.is_open())
   		{
	        getline (MyFile, line);
        	int index = 0;
            istringstream WhiteSpace(line);
            string SubStr;
            T v1, v2;
            WhiteSpace >> SubStr;
            while (WhiteSpace.good()){
                string tempSubStr = SubStr;
                WhiteSpace >> SubStr;
                stringstream convert1(SubStr);
                stringstream convert2(tempSubStr);
                convert1 >> v1;
                convert2 >> v2;
                if(Grams.count(pair<T, T>(v2, v1))){
                    typename  map<pair<T, T>, int>::iterator ii = Grams.find(pair<T, T>(v2, v1));
                    Grams.insert(pair<pair<T, T>, int>(pair<T, T>(v2, v1), (*ii).second+=1));
                    ++index;
                }
                Grams.insert(pair<pair<T, T>, int>(pair<T, T>(v2, v1), 1));
                ++index;
            }

            //printGrams();
            //cout << Grams.size() << endl;
        	MyFile.close();

            setTotalNumGrams(index);
    	}
	    else
	    {
            exception e;
	        e.cantFind = true;
	        throw e;
	    } 

        return  getTotalNumgrams();
	}
    template<class T>
    int BigramMap<T>::numGrams() throw(exception){

        return getTotalNumgrams();
    }

    template<class T>
    int BigramMap<T>::numOfGrams(T first, T second) throw(exception){
        int a = 0;
        for(int i = 0; i < Grams.size(); ++i)
        {
            if(Grams.count(pair<T, T>(first, second))){
                typename map<pair<T, T>, int>::iterator ii = Grams.find(pair<T, T>(first, second));
                return (*ii).second;
            }
         
        }
       

    }

    template<class T>
    pair<T, T> BigramMap<T>::maxGrams() throw(exception){
        int counts[Grams.size()];
        int i = 0;
        for(typename map<pair<T, T>, int>::iterator ii = Grams.begin(); ii != Grams.end(); ++ii)
        {
            counts[i] = (*ii).second;

            //cout << counts[i];
            ++i;
        }
        std::sort(counts, counts + Grams.size());
        int index = counts[Grams.size() - 1];

        for(typename map<pair<T, T>, int>::iterator ii = Grams.begin(); ii != Grams.end(); ++ii)
        {
           if((*ii).second == index){
               //cout << (*ii).first.first << ", " <<  (*ii).first.second << endl;
               return (*ii).first;
           }
        }

    }


    template <class T>
    void BigramMap<T>::print(ostream& out) const{
        for( typename map<pair<T, T>, int>::const_reverse_iterator  ii = Grams.rbegin(); ii != Grams.rend(); ++ii)
        {
            out << (*ii).first.first << ", "  << (*ii).first.second << ": " << (*ii).second << endl;
        }

    }


    template <class T>
    void BigramMap<T>::printGrams() {

        for( typename map<pair<T, T>, int>::iterator ii = Grams.begin(); ii != Grams.end(); ++ii)
        {
            cout << (*ii).first.first << ", "  << (*ii).first.second << ": " << (*ii).second << endl;
        }
    }
}
