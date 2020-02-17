import java.util.Scanner;

public class Videoteka {

    public static void main(String[] args) {
        String[] zanr1 = {"adventure", "comedy", "sci-fi"};
        Film f1 = new Film("Povratak u buducnost", zanr1, 8.5);
        String[] zanr2 = {"adventure", "family", "fantasy"};
        Film f2 = new Film("Hari Poter i zatvorenik iz Askabana", zanr2, 8.0);
        String[] zanr3 = {"drama", "romance"};
        Film f3 = new Film("Titanik", zanr3, 7.8);
        String[] zanr4 = {"adventure", "drama", "fantasy"};
        Film f4 = new Film("Gospodar prstenova: Dve kule", zanr4, 9.3);

        Film[] filmovi = {f1, f2, f3, f4};

        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite ime:");
        String ime = sc.next();
        System.out.println("Unesite omiljeni zanr:");
        String omiljeniZanr = sc.next();
        RegularanClan c1 = new RegularanClan(ime, omiljeniZanr);

        System.out.println("Unesite ime:");
        ime = sc.next();
        System.out.println("Unesite omiljeni zanr:");
        omiljeniZanr = sc.next();
        VipClan c2 = new VipClan(ime, omiljeniZanr);

        System.out.println("Unesite ime:");
        ime = sc.next();
        System.out.println("Unesite omiljeni zanr:");
        omiljeniZanr = sc.next();
        VipClan c3 = new VipClan(ime, omiljeniZanr);

        Clan[] clanovi = {c1, c2, c3};
        for (Clan c : clanovi){
            System.out.println(c);
            System.out.println("------------------------------------");
        }

        c1.iznajmiReg(f3);
        System.out.println(c1);
        c2.iznajmiVip(f1);

        System.out.println();
        c3.iznajmiVip(f3);

        System.out.println("Unesite minimalnu ocenu filma za zanr " + c3.getOmiljeniZanr() +
                " kako bismo Vam preporucili film:");
        double ocena = sc.nextDouble();
        System.out.println("Preporuka: " + c3.preporuka(filmovi, c3.getOmiljeniZanr(), ocena));
        for (int i = 0; i < filmovi.length; i++) {
            if(filmovi[i].getNaziv().equals(c3.preporuka(filmovi, c3.getOmiljeniZanr(), ocena))){
                c3.iznajmiVip(filmovi[i]);
                break;
            }
        }

        System.out.println();
        c1.iznajmiReg(f2);
        c1.vratiReg();
        c1.iznajmiReg(f2);

        c2.iznajmiVip(f3);
        c2.iznajmiVip(f4);

        sc.close();
    }
}
