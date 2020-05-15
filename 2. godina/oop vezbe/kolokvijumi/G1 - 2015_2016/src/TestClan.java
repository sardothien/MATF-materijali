import java.util.Scanner;

public class TestClan {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite podatke o clanu:");
        System.out.print("Unesite ime: ");
        String ime = sc.next();
        System.out.print("Unesite tezinu: ");
        int tezina = sc.nextInt();
        System.out.print("Unesite visinu: ");
        int visina = sc.nextInt();

        //Clan clan = new Clan(ime, tezina, visina);
        //System.out.print(clan);

        System.out.print("Da li je novi clan Student - S ili Regularan - R? ");
        char clanKarakter = sc.next().charAt(0);

        if(clanKarakter == 'S'){
            System.out.print("Unesite prosek: ");
            int prosek = sc.nextInt();
            Student student = new Student(ime, tezina, visina, prosek);
            System.out.println(student);

        }
        else{
            System.out.println("Da li je novi clan Zaposlen - Z ili Nezaposlen - NZ?");
            String zaposlen = sc.next();
            if(zaposlen.charAt(0) == 'Z'){
                Regularni regularni = new Regularni(ime, tezina, visina, zaposlen);
                System.out.println(regularni);
            }
            else{
                System.out.println("Da li nezaposlen ima privilegije? (D/N)");
                char daNe = sc.next().charAt(0);
                if(daNe == 'D'){
                    System.out.println("Unesite koliko popust treba obracunati privilegovanom clanu:");
                    double popust = sc.nextInt();
                    RegularniSaPrivilegijama regularniSaPriv = new RegularniSaPrivilegijama(ime, tezina, visina, zaposlen, popust);
                    System.out.println(regularniSaPriv.getIme() + ", preporucujemo Vam program "
                            + regularniSaPriv.program() + ".");
                    System.out.print("Unesite broj zeljenih termina (8 ili 16): ");
                    int brTermina = sc.nextInt();
                    regularniSaPriv.toString();
                }
            }

        }




        sc.close();
    }
}
