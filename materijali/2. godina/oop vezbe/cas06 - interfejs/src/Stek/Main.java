package Stek;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stek s = new Niz();

        prikaziInstrukcije();
        int i = sc.nextInt();

        // vraca sve vrednosti enum-a
        Operacija opcija = Operacija.values()[i];

        while (opcija != Operacija.EXIT_OPERACIJA){
            if(opcija == Operacija.PUSH_OPERACIJA){
                System.out.println("Unesite element:");
                s.push(sc.nextInt());
            }
            else if (opcija == Operacija.POP_OPERACIJA)
                System.out.println("Sa steka je skinut element: " + s.pop());
            else if (opcija == Operacija.TOP_OPERACIJA)
                System.out.println("Element na vrhu steka je: " + s.top());
            else if(opcija == Operacija.SIZE_OPERACIJA)
                System.out.println("Broj elemenata na steku je: " + s.size());
            s.show();
            prikaziInstrukcije();
            opcija = Operacija.values()[sc.nextInt()];
        }

        sc.close();
    }

    public static void prikaziInstrukcije() {
        System.out.println("unesite operaciju (0 - push, 1 - pop, 2 - top, 3 - size, 4 - exit)");
    }
}
