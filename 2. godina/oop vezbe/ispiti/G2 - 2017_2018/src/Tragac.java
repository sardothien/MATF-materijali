import java.util.Random;

public class Tragac extends ObjekatIgre {

    private Ranac ranac;
    private static Random random = new Random();
    private static String smerKretanja; // dd ili gl

    public Tragac(String naziv, int x, int y, Ranac ranac) {
        super(naziv, x, y);
        this.ranac = ranac;
    }

    public Ranac getRanac() {
        return ranac;
    }

    public static void setSmerKretanja(String sk) {
        Tragac.smerKretanja = sk;
    }

    public boolean pokupiDragulj(Rudnik rudnik){
        return ranac.smestiDragulj(rudnik.getTezinaDragulja());
    }

    @Override
    public void izvrsiAkciju() {
        boolean h = random.nextBoolean();

        if (smerKretanja.equalsIgnoreCase("dd")){
            if (h)
                x++;
            else
                y++;
        }
        else if (smerKretanja.equalsIgnoreCase("gl")){
            if (h)
                x--;
            else
                y--;
        }
        else
            System.out.println("Greska pri unosu smera kretanja!");
    }

    @Override
    public String toString() {
        return "Tragac: " + super.toString() + " ima " + ranac.toString();
    }
}
