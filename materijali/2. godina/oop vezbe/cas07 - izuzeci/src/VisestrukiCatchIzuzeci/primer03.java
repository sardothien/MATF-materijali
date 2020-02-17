package VisestrukiCatchIzuzeci;

import java.util.Scanner;

public class primer03 {
    /* Konstrukcija try-with-resources omogucava da se resurs
       koji koristimo sam zatvori nakon izvrsavanja bloka koda.
     */

    public static void main(String[] args) {

        try(Scanner sc = new Scanner(System.in)) {
            System.out.println(sc.nextLine());
        }
        // nakon izvrsavanja try bloka, poziva se sc.close();
    }
}
