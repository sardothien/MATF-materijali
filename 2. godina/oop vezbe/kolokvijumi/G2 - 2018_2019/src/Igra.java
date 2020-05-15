import java.util.Scanner;

public class Igra {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Unesite ime: ");
        String ime = sc.next();
        System.out.print("Unesite X koordinatu pocetka: ");
        double x = sc.nextDouble();
        System.out.print("Unesite Y koordinatu pocetka: ");
        double y = sc.nextDouble();

        Igrac igrac = new Igrac(ime, x, y);
        System.out.println(igrac);
        System.out.println();

        DeoOpreme[] inventar = new DeoOpreme[5];
        inventar[0] = new DeoOpreme("Viteski Mac", 3000);
        inventar[1] = new DeoOpreme("Buzdovan", 1750);
        inventar[2] = new DeoOpreme("Veliki Stit", 1550);
        inventar[3] = new DeoOpreme("Drevni Oklop", 5000);
        inventar[4] = new DeoOpreme("Napitak za oporavak", 250);

        for (int i = 0; i < 5; i++)
            System.out.println((i+1) + ". " + inventar[i].toString());
        System.out.println();

        int rbrArtikla, j = 0;

        System.out.println("Imate > " + igrac.getZlato() + " < zlata.");
        while(igrac.getZlato() > 0){
            System.out.print("Unesite broj artikla koji zelite da kupite: ");
            rbrArtikla = sc.nextInt();
            while(rbrArtikla < 1 || rbrArtikla > 5){
                System.out.print("Unesite broj artikla koji zelite da kupite: ");
                rbrArtikla = sc.nextInt();
            }
            System.out.println("Kupili ste " + inventar[rbrArtikla-1].toString());
            igrac.kupi(inventar[rbrArtikla-1]);
            j++;
            System.out.println("Imate > " + igrac.getZlato() + " < zlata.");
        }
        System.out.println();

        System.out.println("Ukupno instancirano artikala: " + (DeoOpreme.getBrojObjekataKlaseDeoOpreme() + j));
        System.out.println(igrac);

        sc.close();
    }
}
