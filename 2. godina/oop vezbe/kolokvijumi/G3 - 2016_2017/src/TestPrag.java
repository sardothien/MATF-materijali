import java.util.Scanner;

public class TestPrag {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Naziv datoteke:");
        String ime = sc.next();
        System.out.println("Prava pristupa:");
        String prava = sc.next();

        DatotekaPrag datotekaPrag = new DatotekaPrag(ime, prava);

        System.out.println(datotekaPrag);

        sc.close();
    }
}
