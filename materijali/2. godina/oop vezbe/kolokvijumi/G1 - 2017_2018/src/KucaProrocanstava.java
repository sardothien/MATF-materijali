import java.util.Scanner;

public class KucaProrocanstava {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite ime proroka (jedna rec):");
        String ime = sc.next();
        System.out.println("Unesite broj ostvarenih prorocanstava:");
        int brOstvarenihPr = sc.nextInt();
        System.out.println("Unesite ukupan broj prorocanstava:");
        int ukupanBrProrocanstava = sc.nextInt();

        TarotKarta tk1 = new TarotKarta(0, "Visoka Svestenica", "Italija");
        TarotKarta tk2 = new TarotKarta(1, "Lazov", "Otomansko Carstvo");
        TarotKarta tk3 = new TarotKarta(-1, "Mag", "Nemacka");

        TarotKarta[] karte = {tk1, tk2, tk3};

        TarotProrok prorok = new TarotProrok(ime, brOstvarenihPr, ukupanBrProrocanstava, karte);

        System.out.println("--------------------------------------------");

        System.out.println("Unesite ime proroka (jedna rec):");
        ime = sc.next();
        System.out.println("Unesite broj ostvarenih prorocanstava:");
        brOstvarenihPr = sc.nextInt();
        System.out.println("Unesite ukupan broj prorocanstava:");
        ukupanBrProrocanstava = sc.nextInt();
        System.out.println("Unesite tip kristala:");
        String tipKristala = sc.next();

        KuglaProrok kuglaPr = new KuglaProrok(ime, brOstvarenihPr, ukupanBrProrocanstava, tipKristala);

        System.out.println("--------------------------------------------");

        System.out.println(prorok.getIme() + " - proceni uspesnost: " + prorok.getProcenatUspesnosti());
        System.out.println(kuglaPr.getIme() + " - proceni uspesnost: " + kuglaPr.getProcenatUspesnosti());

        System.out.println("--------------------------------------------");

        System.out.println(prorok.getIme() + " prorice: " + prorok.proreci(tk1));
        System.out.println(kuglaPr.getIme() + " prorice: " + kuglaPr.prorekni());

        sc.close();
    }
}
