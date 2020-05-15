public class RegularniSaPrivilegijama extends Regularni {

    private double popust;
    public int brojRegularnih = 0;

    public RegularniSaPrivilegijama(String ime, int tezina, int visina, String kategorija, double popust) {
        super(ime, tezina, visina, kategorija);
        this.popust = popust;
        brojRegularnih++;
    }

    public int getBrojRegularnih() {
        return brojRegularnih;
    }

    public double clanarinaPrivilegovanog(){
        return (clanarinaRegularnog()*popust) / 100;
    }

    @Override
    public String toString() {
        return "Cena clanarine: " + clanarinaRegularnog() + '\n' +
                "Uclanjeno je " + brojClanova + " clanova, a od toga " +
                brojRegularnih + " regularnih sa privilegijama.";
    }
}
