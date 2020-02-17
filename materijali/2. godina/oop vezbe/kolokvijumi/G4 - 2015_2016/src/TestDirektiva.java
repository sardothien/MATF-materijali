import java.util.Scanner;

public class TestDirektiva {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("ime osobe:");
        String ime = sc.next();
        System.out.println("naredba:");
        String naredba = sc.next();
        System.out.println();

        Direktiva direktiva = new Direktiva(ime, naredba);
        System.out.println(direktiva.toString());

        sc.close();
    }
}
