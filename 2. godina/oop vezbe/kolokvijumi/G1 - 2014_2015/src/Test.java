import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite vrednost x izmedju 0 i 2:");
        double x = sc.nextDouble();
        System.out.println("Unesite funkciju (s ili z):");
        char fja = sc.next().charAt(0);

        int a, b;

        if(fja == 's'){
            System.out.println("Unesite a:");
            a = sc.nextInt();
            System.out.println("Unesite b:");
            b = sc.nextInt();

            Clan clan = new Clan(a, b);
            Sinusoida sinusoida = new Sinusoida(x, clan);
            System.out.println(sinusoida.toString());
            System.out.printf("Vrednost: %.2f", sinusoida.vrednost());
        }
        else if(fja == 'z'){
            System.out.println("Unesite broj clanova zbira:");
            int brClanova = sc.nextInt();
            System.out.println();

            Clan[] clanovi = new Clan[brClanova];

            for (int i = 0; i < brClanova; i++) {
                System.out.println("Unesite a za " + (i+1) + ". clan:");
                a = sc.nextInt();
                System.out.println("Unesite b za " + (i+1) + ". clan:");
                b = sc.nextInt();
                clanovi[i] = new Clan(a, b);
            }
            System.out.println();

            ZbirSinusoida zbirSinusoida = new ZbirSinusoida(x, clanovi);

            System.out.println(zbirSinusoida.toString());
            System.out.printf("Vrednost: %.2f", zbirSinusoida.vrednost());
        }

        sc.close();
    }
}
