import java.util.Arrays;
import java.lang.String;

public class klasaArrays02 {
    // Koriscenje fja Arrays.fill i Arrays.copyOfRange
    public static void main(String[] args) {
        // Niz duzine 50 gde su svi elem. jednaki 42
        int[] a = new int[50];
        Arrays.fill(a, 42);
        ispisi("a", a);

        // Iskopirati vrednosti nekog niza za date indekse
        int[] b = Arrays.copyOfRange(a, 20, 30);
        ispisi("b",b);

        // Iskopirati ceo niz
        int[] c = Arrays.copyOf(a, a.length);
        ispisi("c",c);
    }

    static void ispisi(String name, int[] a){
        System.out.println(name + ": " + Arrays.toString(a));
    }
}
