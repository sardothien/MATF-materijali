package Set;

import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class Primer01 {

    // Java poseduje interfejs Set i nekoliko implementacija za skup
    // Najcesce cemo koristiti impl. skupa preko stabla, TreeSet

    public static void main(String[] args) {

        Set<Integer> brojevi = new TreeSet<>();

        for (int i = 0; i < 100; i++)
            brojevi.add(i%20);

        System.out.println("foreach iteracija kroz skup:");
        for (Integer i: brojevi)
            System.out.print(i + " ");
        System.out.println();
        System.out.println("--------------------------------------------------------");

        System.out.println("Iterator iteracija kroz skup:");
        Iterator<Integer> it = brojevi.iterator();
        while(it.hasNext())
            System.out.print(it.next() + " ");
        System.out.println();
        System.out.println("--------------------------------------------------------");
    }
}
