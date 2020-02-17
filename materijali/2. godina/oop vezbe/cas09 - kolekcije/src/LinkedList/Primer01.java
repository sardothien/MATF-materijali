package LinkedList;

import java.util.Arrays;
import java.util.LinkedList;

public class Primer01 {

    public static void main(String[] args) {

        LinkedList<String> imena = new LinkedList<>(Arrays.asList(
                "Blue ranger", "Red ranger", "White ranger", "Yellow ranger"));

        System.out.println("Sadrzaj liste (foreach):");
        for (String ime : imena)
            System.out.print(ime + " ");
        System.out.println();
        System.out.println("--------------------------------------------------");

        System.out.println("Sadrzaj liste (normalni for):");
        for (int i = 0; i < imena.size(); i++)
            System.out.print(imena.get(i) + " ");
        System.out.println();
        System.out.println("--------------------------------------------------");

        System.out.println("Sadrzaj liste (toString):");
        System.out.println(imena);
        System.out.println("--------------------------------------------------");

        // dodavanje elemenata
        imena.addLast("Rita");
        imena.addFirst("Alpha 5");

        System.out.println("Nakon dodavanja na pocetak i kraj:\n" + imena);
        System.out.println("--------------------------------------------------");

        // uklanjanje elemenata
        imena.removeFirst();
        imena.removeLast();

        System.out.println("Nakon uklanjanja elemenata:\n" + imena.get(3));
        System.out.println("--------------------------------------------------");

        System.out.println("Nakon uklanjanja elementa: " + imena.get(3));
        imena.remove(3);
        System.out.println(imena);
    }
}
