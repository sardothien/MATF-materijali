import java.util.Scanner;

public class TestStambeniObjekat {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        /*System.out.println("Unesite povrsinu stana:");
        double P = sc.nextDouble();
        System.out.println("Unesite broj stanara u stanu:");
        int brStanara = sc.nextInt();

        Stan stan = new Stan(P, brStanara);
        System.out.println(stan.toString());*/

        System.out.println("Unesite adresu stambenog objekta:");
        String adresa = sc.nextLine();
        System.out.println("Unesite stambeni objekat koji zelite (k ili z):");
        char objekat = sc.next().charAt(0);

        double povrsina;
        int brStanara;
        StambeniObjekat stambeniObjekat;

        if(objekat == 'z'){
            System.out.println("Unesite broj stanovnika zgrade:");
            int brStanovnika = sc.nextInt();
            Stan[] stanovi = new Stan[brStanovnika];

            for (int i = 0; i < brStanovnika; i++) {
                System.out.println("Unesite povrsinu " + (i+1) + ". stana:");
                povrsina = sc.nextDouble();
                System.out.println("Unesite broj stanara " + (i+1) + ". stana:");
                brStanara = sc.nextInt();
                stanovi[i] = new Stan(povrsina, brStanara);
            }

            stambeniObjekat = new Zgrada(adresa, stanovi);
        }
        else{
            System.out.println("Unesite broj kvadrata i broj stanara kuce:");
            povrsina = sc.nextDouble();
            brStanara = sc.nextInt();
            Stan s = new Stan(povrsina, brStanara);
            stambeniObjekat = new Kuca(adresa, s);
        }

        System.out.println("Unesite cenu poreza po kvadratu:");
        int cena = sc.nextInt();

        System.out.println(stambeniObjekat.toString());
        System.out.println("Ukupni porez koji treba da bude placen je: " + stambeniObjekat.porez(cena));

        sc.close();
    }
}
