package dodatnoTokoviPodataka;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;

public class Example06SumOptional {

    // Optional je klasa koja cuva rezultat neke operacije
    // koja potencijalno moze biti neuspesna.
    // U slucaju da je rezultat uspesan, Optional u sebi sadrzi
    // dobijenu vrednost, a ukoliko je neuspesan, Optional
    // ima postavljen indikator da rezultat ne postoji.
    // Slucajevi upotrebe:
    // - Sumiranje niza (niz potencijalno prazan)
    // - Skidanje sa vrha steka (stek potencijalno prazan)
    public static Optional<Integer> sumaListe(List<Integer> xs) {
        Optional<Integer> suma = xs.stream().reduce((x1, x2) -> x1 + x2);
        return suma;
    }

    public static int proizvodListe(List<Integer> xs) {
        // Za slucaj da metodu 'reduce' prosledimo neutral, a prosledi
        // se prazna lista, mozemo izbeci Optional konstrukciju i vratiti
        // vrednost neutrala.
        int proizvod = xs.stream().reduce(1, (x1, x2) -> x1*x2);
        return proizvod;
    }

    public static void main(String[] args) {
        List<Integer> xs = new ArrayList<>(
                Arrays.asList(1, 2, 3, 4, 5, 6)
        );

        Optional<Integer> suma = sumaListe(xs);

        // Proveru da li Optional ima rezulat
        // mozemo izvrsiti metodom 'isPresent'
        // a vrednost mozemo procitati koristeci
        // metod 'get'.
        if (suma.isPresent())
            System.out.println("Suma niza: " + suma.get());
        else
            System.out.println("Niz je prazan.");

        System.out.println("Proizvod liste: " + proizvodListe(xs));

    }
}
