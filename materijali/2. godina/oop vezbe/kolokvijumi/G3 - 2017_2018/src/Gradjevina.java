import java.util.Scanner;

public class Gradjevina {
    public static void main(String[] args) {
        Zvucnik z1 = new Zvucnik("Yamaha", "HS8", 75);
        Zvucnik z2 = new Zvucnik("Yamaha", "HS7", 60);
        Zvucnik z3 = new Zvucnik("Logitec", "Z313", 25);
        Zvucnik[] zvucnici = {z1, z2, z3};

        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite naziv skladista:");
        String ime = sc.next();
        System.out.println("Unesite duzinu skladista:");
        double duzina = sc.nextDouble();
        System.out.println("Unesite sirinu skladista:");
        double sirina = sc.nextDouble();
        System.out.println("Unesite stranicu palete:");
        double stranicaPalete = sc.nextDouble();

        Skladiste s = new Skladiste(ime, duzina, sirina, stranicaPalete);
        System.out.println(s);
        System.out.println();

        s.dodajPalete(8);
        s.dodajPalete(4);
        s.dodajPalete(2);

        System.out.println("-----------------------------------");

        System.out.println("Unesite naziv muzicke sale:");
        ime = sc.next();
        System.out.println("Unesite duzinu muzicke sale:");
        duzina = sc.nextDouble();
        System.out.println("Unesite sirinu muzicke sale:");
        sirina = sc.nextDouble();
        System.out.println("Unesite broj mesta:");
        int brMesta = sc.nextInt();

        MuzickaSala m = new MuzickaSala(ime, duzina, sirina, brMesta, zvucnici);
        System.out.println(m);
        System.out.println();

        m.getOzvucenje()[0].switchOnOff();
        m.getOzvucenje()[1].switchOnOff();
        m.getOzvucenje()[2].switchOnOff();

        if(m.proveriOzvucenje())
            System.out.println("Dobro ozvuceno!");
        else
            System.out.println("Lose ozvuceno!");

        for (int i = 0; i < brMesta; i++) {
            m.zauzmiMesto(i);
        }

        if(m.proveriOzvucenje())
            System.out.println("Dobro ozvuceno!");
        else
            System.out.println("Lose ozvuceno!");
    }
}
