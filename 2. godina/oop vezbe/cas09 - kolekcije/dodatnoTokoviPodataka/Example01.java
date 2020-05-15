package dodatnoTokoviPodataka;

import java.util.Arrays;
import java.util.List;

public class Example01 {
    public static void main(String[] args) {
        // ---------------------------------------------------------------------
        // filter(p) - Filter je funkcija koja se primenjuje nad kolekcijom
        // podataka. Radi tako sto predikat 'p' (funkcija p ispituje uslov i
        // vraca true ili false) primeni nad svim elementima polazne kolekcije,
        // i zadrzava samo one elemente koji zadovoljavaju predikat.
        //
        // Primer: xs = [1, 2, 3, 4, 5, 6]
        //  xs.filter(even) ce dati [2, 4, 6]
        //
        // map(f) - Mapa je funkcija koja se primenjuje nad kolekcijom podataka.
        // Funkcija 'f' koja se prosledjuje se primenjuje na svaki element
        // polazne kolecije.
        //
        // Primer: xs = [2, 4, 6]
        // xs.map(x -> x*x) ce dati [4, 16, 36]
        // ---------------------------------------------------------------------

        List<String> myList = Arrays.asList("a1", "a2", "b1", "c2", "c1");

        myList.stream()
              .filter(s -> s.startsWith("c"))
              .map(String::toUpperCase)
              .sorted()
              .forEach(System.out::println);
    }
}
