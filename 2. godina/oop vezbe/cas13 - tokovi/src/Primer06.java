import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;

public class Primer06 {

    public static Optional<Integer> sumaListe(List<Integer> xs){
        Optional<Integer> suma = xs.stream().reduce((x1, x2) -> x1+x2);
        return suma;
    }

    public static int proizvodListe(List<Integer> xs){
        int proizvod = xs.stream().reduce(1, (x1, x2) -> x1*x2);
        return proizvod;
    }

    public static void main(String[] args) {
        List<Integer> xs = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6));

        Optional<Integer> suma = sumaListe(xs);

        if (suma.isPresent())
            System.out.println("Suma: " + suma.get());
        else
            System.out.println("Niz je prazan.");

        System.out.println("Proizvod: " + proizvodListe(xs));
    }
}
