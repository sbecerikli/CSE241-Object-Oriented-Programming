
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.LinkedHashMap;
/**
 * Created by Seyfullah Becerikli on 29/12/2016.
 */
public class BigramMap<E extends Comparable<E>> implements Bigram<E> {
    private Map<Pair<E, E>, Integer> Grams;
    private int totalNumGramsX;
    private int numOfGramsX;

    public BigramMap(int dataType) {
        Grams = new LinkedHashMap<>();
    }

    @Override



    public void readFile(String filename) throws IOException {

        //Grams.put(new Pair<E, E>((E)"asd", (E)"asdf"), 2);
        //System.out.println(Grams.get(new Pair<E, E>((E)"asd", (E)"asdf")));
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(filename));
            String line;
            line = br.readLine();
            //System.out.println(line);
            String[] ParsedLine = line.split(" ");
            //System.out.println("len: " + ParsedLine.length);
            for (int i = 0; i < ParsedLine.length - 1; ++i) {
                if(Grams.containsKey(new Pair<E, E>((E)ParsedLine[i], (E)ParsedLine[i+1]))){
                    int count = Grams.get(new Pair<E, E>((E)ParsedLine[i], (E)ParsedLine[i+1]));
                    Grams.remove(new Pair<E, E>((E)ParsedLine[i], (E)ParsedLine[i+1]));
                    Grams.put(new Pair<E, E>((E)ParsedLine[i], (E)ParsedLine[i+1]), count+1);
                    //System.out.println("girdi" + Grams.get(new Pair<E, E>((E)ParsedLine[i], (E)ParsedLine[i+1])));
                }
                else {
                    Grams.put(new Pair<E, E>((E) ParsedLine[i], (E) ParsedLine[i + 1]), 1);
                }
            }

        }
        finally {
            br.close();
        }
    }

    public Map<Pair<E, E>, Integer> getGrams() {
        return Grams;
    }

    public void setGrams(Map<Pair<E, E>, Integer> grams) {
        Grams = grams;
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

    @Override
    public int numGrams() {
        return Grams.size();
    }

    @Override
    public int numOfGrams(E first, E second) {
        for (Pair p : getGrams().keySet()){
            if(p.getFirst().equals(first.toString()) && p.getSecond().equals(second.toString())){
                return getGrams().get(p);
            }
        }
        return 0;
    }

    @Override
    public String toString() {
        return "BigramMap{\n" +
                Grams  +
                '}';
    }

}