import java.util.Scanner;

public class TestPredikcija {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite ime, tezinu i pol ('m', 'z') osobe:");
        String ime = sc.next();
        double tezina = sc.nextDouble();
        char pol = sc.next().charAt(0);

        Osoba osoba = new Osoba(ime, tezina, pol);

        System.out.println("Unesite pravu visinu osobe:");
        double visina = sc.nextDouble();

        System.out.println("Izaberite predikciju:" + '\n' +
                "1) Naivna predikcija" + '\n' +
                "2) Linearna regresija");
        int predikcija = sc.nextInt();

        if(predikcija == 1) {
            System.out.println("Unesite uvecanje:");
            int uvecanje = sc.nextInt();

            Predikcija pn = new PredikcijaNaivna(osoba, uvecanje);
            System.out.println(pn);
            System.out.println();
            System.out.println(osoba);

            System.out.println("Dobijena visina: " + pn.visina() + "kg");
            System.out.println("Greska: " + pn.greska(visina, pn.visina()) + "kg");
        }
        else if(predikcija == 2){
            System.out.println("Unesite keoficijent a:");
            double a = sc.nextDouble();
            System.out.println("Unesite koeficijent b:");
            double b = sc.nextDouble();

            Predikcija lr = new PredikcijaLinearnaRegresija(osoba, a, b);

            System.out.println(lr);
            System.out.println();
            System.out.println(osoba);
            System.out.println("Dobijena visina: " + lr.visina() + "kg");
            System.out.println("Greska: " + lr.greska(visina, lr.visina()) + "kg");
        }
    }
}
