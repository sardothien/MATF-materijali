import java.util.Scanner;

public class Student extends Clan {
    private int prosek;

    public Student(String ime, int tezina, int visina, int prosek) {
        super(ime, tezina, visina);
        this.prosek = prosek;
    }

    public double clanarina(){
        System.out.println(getIme() + ", preporucujemo Vam " + program() + " program.");
        Scanner sc = new Scanner(System.in);
        double clanarina;

        if(program().equals("Kardio")){
            int brojTermina = sc.nextInt();
            int cena = 700;
            clanarina = brojTermina*cena;
        }
        else{
            System.out.println("Unesite zeljeni deo dana: ceo - C, pre_podne - PR. ");
            String deoDana = sc.next();
            if(deoDana.charAt(0) == 'C')
                clanarina = 4000;
            else
                clanarina = 2000;
        }

        if(prosek > 8)
            clanarina = (clanarina*85)/100;

        return clanarina;
    }

    @Override
    public String toString() {
        return "Cena clanarine: " + clanarina() + "\n" +
                "Uclanjeno je " + brojClanova + " clanova, a od toga 0 " +
                "regularnih sa privilegijama.";
    }
}
