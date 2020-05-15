import java.util.Arrays;

public class MuzickaSala extends Prostorija {

    private int brMesta;
    private boolean[] mesta;
    private Zvucnik[] ozvucenje;
    static int brInstanci = 0;

    public MuzickaSala(String naziv, double duzina, double sirina, int brMesta, Zvucnik[] ozvucenje) {
        super(naziv, duzina, sirina);
        this.brMesta = brMesta;
        mesta = new boolean[brMesta];
        this.ozvucenje = ozvucenje;
        brInstanci++;
    }

    public static int brojInstanci(){
        return brInstanci;
    }

    public int getBrMesta() {
        return brMesta;
    }

    public boolean[] getMesta() {
        return mesta;
    }

    public Zvucnik[] getOzvucenje() {
        return ozvucenje;
    }

    public void zauzmiMesto(int i){
        if(mesta[i])
            System.out.println("Mesto pod rednim brojem " + i + " je vec zauzeto!");
        else
            mesta[i] = true;
    }

    public boolean proveriOzvucenje(){
        int ukupnaSnaga = 0;
        for (Zvucnik z: ozvucenje)
            if(z.isUkljucen())
                ukupnaSnaga += z.getSnaga();

        double k = 2.2;
        for(boolean m: mesta) {
            if (!m) {
                k -= 0.2;
                break;
            }
        }

        return ukupnaSnaga/(getDuzina()*getSirina()) >= k;
    }

    @Override
    public String toString() {
        return "Muzicka sala " + super.toString() + " sa " + brMesta
                + " mesta za sedenje.";
    }
}
