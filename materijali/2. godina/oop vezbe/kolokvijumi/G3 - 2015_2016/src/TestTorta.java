import java.util.Scanner;

public class TestTorta {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        /* System.out.print("Naziv sastojka: ");
        String naziv = sc.next();
        System.out.print("Kolicina: ");
        double kolicina = sc.nextDouble();
        System.out.print("Jedinica mere: ");
        String jedinica = sc.next();

        Sastojak sastojak = new Sastojak(naziv, kolicina, jedinica);

        System.out.print(sastojak); */

        System.out.print("Unesite broj sastojaka: ");
        int br = sc.nextInt();
        System.out.println();

        Sastojak[] sastojci = new Sastojak[br];
        String naziv;
        double kolicina;
        String jedinica;

        for (int i = 0; i < br; i++) {
            System.out.println("Naziv sastojka: ");
            naziv = sc.next();
            if(!Sastojak.dozvoljenSastojak(naziv)){
                System.out.println("Nedozvoljen sastojak");
                i--;
                continue;
            }
            System.out.print("Kolicina: ");
            kolicina = sc.nextDouble();
            System.out.println("Jedinica mere: ");
            jedinica = sc.next();
            sastojci[i] = new Sastojak(naziv, kolicina, jedinica);
        }

        System.out.print("Unesite tezinu recepta: ");
        int tezina = sc.nextInt();
        System.out.print("Unesite voce: ");
        String voce = sc.next();

        VocnaTorta vt = new VocnaTorta(sastojci, tezina, voce);

        System.out.println();
        System.out.println(vt);

        for (int i = 0; i < sastojci.length; i++)
            sastojci[i].setKolicina(sastojci[i].getKolicina()/2);

        VocnaTorta pola = new VocnaTorta(sastojci, tezina, voce);
        System.out.println();
        System.out.println("Pola mere: ");
        System.out.println(pola);

        sc.close();
    }
}
