

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

/**
 * Created by Seyfullah Becerikli on 29/12/2016.
 */
public class BigramDyn<E extends Comparable<E>> implements Bigram<E> {
    private Pair<E, E>[] Grams;
    private int [] GramsCount;
    private int totalNumGramsX;
    private int numOfGramsX;
    private int size;
    private int capacity;

    public BigramDyn(){

    }

    public BigramDyn(int dataType){
        Grams = new Pair[50];
        GramsCount = new int[50];
        totalNumGramsX = 0;
        numOfGramsX = 0;
        size = 0;
        capacity = 50;
    }

    public BigramDyn(BigramDyn b){
        this.Grams = b.Grams;
        this.GramsCount = b.GramsCount;
        this.totalNumGramsX = b.totalNumGramsX;
        this.numOfGramsX = b.numOfGramsX;
        this.size = b.size;
        this.capacity = b.capacity;
    }

    @Override
    public void readFile(String filename) throws IOException {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(filename));
            String line;
            line = br.readLine();
            int index = 0;
            //System.out.println(line);
            String[] ParsedLine = line.split(" ");
            //System.out.println("len: " + ParsedLine.length);
            int i;
            for (i = 0; i < ParsedLine.length - 1; ++i) {
                if(search(new Pair<E, E>((E)ParsedLine[i], (E)ParsedLine[i+1]), index)){
                    GramsCount[index]+=1;
                    System.out.println("girdi");
                }
                else{
                    insert(new Pair<E, E>((E)ParsedLine[i], (E)ParsedLine[i+1]), 1);
                }

            }
            setSize(i);

        }
        finally {
            br.close();
        }
    }
    public boolean search(Pair<E, E> p, int index){
        for (int i = 0; i < getSize(); i++) {
            if(Grams[i].getFirst().compareTo(p.getFirst()) == 0 && Grams[i].getSecond().compareTo(p.getSecond()) == 0){
                index = i;
                return true;
            }
        }
        return false;
    }

    public void insert(Pair<E, E> p, int count){
        if(getSize() == getCapacity()){
            Pair<E, E> tempGrams[] = new Pair[getCapacity() + 10];
            int [] tempGramsCount = new int[getCapacity() + 10];
            setCapacity(getCapacity() + 10);
            for (int i = 0; i < getSize(); i++) {
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

    @Override
    public int numGrams() {
        return getSize();
    }

    @Override
    public int numOfGrams(E first, E second) {
        for (int i = 0; i < getSize()-1; ++i){
            if(Grams[i].getFirst().equals(first.toString()) && Grams[i].getSecond().equals(second.toString())){
                return GramsCount[i];
            }
        }
        return 0;
    }

    public Pair<E, E>[] getGrams() {
        return Grams;
    }

    public void setGrams(Pair<E, E>[] grams) {
        Grams = grams;
    }

    public int[] getGramsCount() {
        return GramsCount;
    }

    public void setGramsCount(int[] gramsCount) {
        GramsCount = gramsCount;
    }

    public int getTotalNumGramsX() {
        return totalNumGramsX;
    }

    public void setTotalNumGramsX(int totalNumGramsX) {
        this.totalNumGramsX = totalNumGramsX;
    }

    public int getNumOfGramsX() {
        return numOfGramsX;
    }

    public void setNumOfGramsX(int numOfGramsX) {
        this.numOfGramsX = numOfGramsX;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < getSize()-1; i++) {
            sb.append(Grams[i] + " , " + GramsCount[i] );
        }
        return sb.toString();
    }

}
