package Red;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Red q = new Niz();

        prikaziInstrukcije();
        int i = sc.nextInt();

        Operacija opcija = Operacija.fromInt(i);

        while (opcija != Operacija.EXIT_OPERACIJA){
            if (opcija == Operacija.ADD_OPERACIJA) {
                System.out.println("Unesite element:");
                q.add(sc.nextInt());
            }
            else if (opcija == Operacija.REMOVE_OPERACIJA)
                System.out.println("Iz reda je izbacen element: " + q.remove());
            else if (opcija == Operacija.HEAD_OPERACIJA)
                System.out.println("Na pocetku reda je element: " + q.head());
            else if (opcija == Operacija.BACK_OPERACIJA)
                System.out.println("Na kraju reda je element: " + q.back());
            else if (opcija == Operacija.SIZE_OPERACIJA) {
                System.out.println("Broj elemenata reda: " + q.size());
            }
            q.show();
            prikaziInstrukcije();

            opcija = Operacija.fromInt(sc.nextInt());
        }

        sc.close();
    }

    public static void prikaziInstrukcije() {
        System.out.println("Unesite operaciju (0 - add, 1 - remove, 2 - head, 3 - back, 4 - size, 5 - exit)");
    }
}
