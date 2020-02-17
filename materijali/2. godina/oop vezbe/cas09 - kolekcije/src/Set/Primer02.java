package Set;

import java.util.Arrays;
import java.util.Set;
import java.util.TreeSet;

public class Primer02 {

    public static void main(String[] args) {

        Set<Integer> s1 = new TreeSet<>(Arrays.asList(1, 2, 3, 4, 5));
        Set<Integer> s2 = new TreeSet<>(Arrays.asList(4, 5, 6, 7, 8));

        System.out.println("S1: " + s1);
        System.out.println("S2: " + s2);
        System.out.println("------------------------------------");

        Set<Integer> unija = new TreeSet<>(s1);
        unija.addAll(s2);
        System.out.println("Unija: " + unija);
        System.out.println("------------------------------------");

        Set<Integer> presek = new TreeSet<>(s1);
        presek.retainAll(s2);
        System.out.println("Presek: " + presek);
        System.out.println("------------------------------------");

        Set<Integer> razlika = new TreeSet<>(s1);
        razlika.removeAll(s2);
        System.out.println("Razlika: " + razlika);
    }
}
