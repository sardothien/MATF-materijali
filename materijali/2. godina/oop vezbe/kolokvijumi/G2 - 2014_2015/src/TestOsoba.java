import java.util.Scanner;

public class TestOsoba {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite dan, mesec i godinu danasnjeg datuma:");
        int dan = sc.nextInt();
        int mesec = sc.nextInt();
        int godina = sc.nextInt();

        Datum datum = new Datum(dan, mesec, godina);
        System.out.println(datum.toString());

        Osoba zena, muz;

        System.out.println("Unesite podatke o zeni:\nIme i prezime:");
        sc.nextLine();
        String ime = sc.nextLine();
        System.out.println("Unesite \"datum\" ako je poznat datum rodjenja osobe, a " +
                "\"jmbg\" ako je poznat jmbg");
        String tip = sc.next();
        if(tip.equalsIgnoreCase("datum")){
            System.out.println("Unesite dan, mesec i godinu rodjenja:");
            dan = sc.nextInt();
            mesec = sc.nextInt();
            godina = sc.nextInt();
            Datum rodjendan1 = new Datum(dan, mesec, godina);
            zena = new OsobaDatum(ime, 'z', rodjendan1);
        }
        else{
            System.out.println("Unesite JMBG osobe:");
            String jmbg = sc.next();
            Datum rodjendan2 = new Datum(dan, mesec, godina);
            zena = new OsobaJMBG(ime, 'z', jmbg);
        }

        System.out.println("Unesite podatke o muzu:\nIme i prezime:");
        sc.nextLine();
        ime = sc.nextLine();
        System.out.println("Unesite \"datum\" ako je poznat datum rodjenja osobe, a " +
                "\"jmbg\" ako je poznat jmbg");
        tip = sc.next();
        if(tip.equalsIgnoreCase("datum")){
            System.out.println("Unesite dan, mesec i godinu rodjenja:");
            dan = sc.nextInt();
            mesec = sc.nextInt();
            godina = sc.nextInt();
            Datum rodjendan1 = new Datum(dan, mesec, godina);
            muz = new OsobaDatum(ime, 'm', rodjendan1);
        }
        else{
            System.out.println("Unesite JMBG osobe:");
            String jmbg = sc.next();
            Datum rodjendan2 = new Datum(dan, mesec, godina);
            muz = new OsobaJMBG(ime, 'm', jmbg);
        }

        System.out.println(zena.toString());
        System.out.println(muz.toString());
        System.out.println(zena.getIme() + " danas ima " + zena.brojGodinaOsobe(datum) + " god.");
        System.out.println(muz.getIme() + " danas ima " + muz.brojGodinaOsobe(datum) + " god.");

        if((zena.brojGodinaOsobe(datum) % 7) < (muz.brojGodinaOsobe(datum) % 7))
            System.out.println("Ako danas naprave bebu, ona ce biti devojcica.");
        else
            System.out.println("Ako danas naprave bebu, ona ce biti decak.");


        sc.close();
    }
}
