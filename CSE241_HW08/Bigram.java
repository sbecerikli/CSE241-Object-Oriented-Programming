import java.io.IOException;

/**
 * Created by Seyfullah Becerikli on 29/12/2016.
 */
public interface Bigram<E> {

    void readFile(String filename) throws IOException;
    int numGrams();
    int numOfGrams(E first, E second);

}
