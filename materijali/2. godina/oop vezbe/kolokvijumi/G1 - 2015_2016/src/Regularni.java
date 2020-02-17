import java.util.Scanner;

public class Regularni extends Clan {

    private String kategorija;

    public Regularni(String ime, int tezina, int visina, String kategorija) {
        super(ime, tezina, visina);
        this.kategorija = kategorija;
    }

    public double clanarinaRegularnog(){
        System.out.println(getIme() + ", preporucujemo Vam " + program() + " program.");
        Scanner sc = new Scanner(System.in);
        double clanarinaReg;

        if(program().equals("Kardio")){
            int brojTermina = sc.nextInt();
            int cena = 700;
            clanarinaReg = brojTermina*700;
        }
        else{
            if(kategorija.charAt(0) == 'Z')
                clanarinaReg = 6000;
            else
                clanarinaReg = 4000;
        }

        return clanarinaReg;
    }

    @Override
    public String toString() {
        return "Cena clanarine: " + clanarinaRegularnog() + '\n' +
                "Uclanjeno je " + brojClanova + " clanova, a od toga 0 " +
                "regularnih sa privilegijama.";
    }
}
