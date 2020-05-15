import java.util.Scanner;

public class TestVektori {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Uneti koordinate prvog vektora:");
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        double z = sc.nextDouble();
        Vektor v1 = new Vektor(x, y, z);

        System.out.println("Uneti koordinate drugog vektora:");
        x = sc.nextDouble();
        y = sc.nextDouble();
        z = sc.nextDouble();
        Vektor v2 = new Vektor(x, y, z);

        System.out.println("Uneti koordinate treceg vektora:");
        x = sc.nextDouble();
        y = sc.nextDouble();
        z = sc.nextDouble();
        Vektor v3 = new Vektor(x, y, z);

        SkalarniProizvod sp = new SkalarniProizvod(v1, v2);
        MesovitiProizvod mp = new MesovitiProizvod(v1, v2, v3);

        System.out.println(sp);
        System.out.println(mp);

        sc.close();
    }
}
