import java.util.Scanner;

public class Dvoboj {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String ime1, ime2;
        System.out.print("Unesite ime prvog deteta: ");
        ime1 = sc.next();
        System.out.print("Unesite ime drugog deteta: ");
        ime2 = sc.next();

        Dete d1 = new Dete(ime1);
        Dete d2 = new Dete(ime2);

        Jabuka jabuka = new Jabuka("crvena", 220, 60);
        Supa supa = new Supa(60, 150, 10);

        d1.dodajJelo(supa);
        d1.dodajJelo(jabuka);


        d2.dodajJelo(supa);
        d2.dodajJelo(jabuka);

        dvoboj(d1, d2);

        sc.close();
    }

    static void dvoboj(Dete d1, Dete d2){
        System.out.println("\nDok se deca gledaju popreko dvoboj se zahuhtava.\n");

        d1.getJela()[0].baci();
        System.out.println(d1.getIme() + " je uspesno pogodio osobu koja se nesretno zove " + d2.getIme());
        System.out.println();
        d1.getJela()[1].baci();
        System.out.println(d1.getIme() + " je uspesno pogodio osobu koja se nesretno zove " + d2.getIme());
        System.out.println();

        d2.getJela()[0].baci();
        System.out.println(d2.getIme() + " je uspesno pogodio osobu koja se nesretno zove " + d1.getIme());
        System.out.println();
        d2.getJela()[1].baci();
        System.out.println(d2.getIme() + " je uspesno pogodio osobu koja se nesretno zove " + d1.getIme());
    }
}
