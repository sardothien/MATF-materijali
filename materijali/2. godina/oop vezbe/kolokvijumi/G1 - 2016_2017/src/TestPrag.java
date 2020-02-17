import java.util.Scanner;

public class TestPrag {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite ime, tezinu i pol coveka.");
        String ime = sc.next();
        double tezina = sc.nextDouble();
        String pol = sc.next();

        Osoba o = new Osoba(ime, tezina, pol.charAt(0));
        System.out.println(o);

        sc.close();
    }
}
