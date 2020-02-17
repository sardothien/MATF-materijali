import java.util.Scanner;

public class TestPrave {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite koeficijente jednacine prave p:");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();

        Prava p = new Prava(a, b, c);

        System.out.println("Izaberite relaciju (t ili p):");
        char relacija = sc.next().charAt(0);

        if(relacija == 't'){
            System.out.println("Unesite koordinate tacke T:");
            double x = sc.nextDouble();
            double y = sc.nextDouble();
            PravaITacka pt = new PravaITacka(p, x, y);
            System.out.println(pt);

            if(pt.odnos())
                System.out.println("Tacka T pripada pravoj p.");
            else {
                System.out.println("Tacka T ne pripada pravoj p.");
                System.out.printf("d(T, p) = %.2f", pt.izracunaj());
            }
        }
        else{
            System.out.println("Unesite koeficijente jednacine prave q:");
            a = sc.nextDouble();
            b = sc.nextDouble();
            c = sc.nextDouble();
            Prava q = new Prava(a, b, c);

            PravaIPrava pp = new PravaIPrava(p, q);
            System.out.println(pp);

            if(pp.odnos()) {
                System.out.println("Prave p i q se seku.");
                System.out.printf("<(p, q) = %.2f", pp.izracunaj());
            }
            else
                System.out.printf("Prave p i q su paralelne.");
        }

        sc.close();
    }
}
