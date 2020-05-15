import java.util.Arrays;

public class Igrac extends PokretniEntitet {

    private String ime;
    private DeoOpreme[] inventar;
    private int zlato;

    public Igrac(double brzina, double ugao, String ime, int zlato) {
        super(brzina, ugao);
        this.ime = ime;
        this.inventar = new DeoOpreme[5];
        this.zlato = zlato;
    }

    public Igrac(double x, double y, int vitalnost, double brzina, double ugao, String ime, int zlato) {
        super(x, y, vitalnost, brzina, ugao);
        this.ime = ime;
        this.inventar = new DeoOpreme[5];
        this.zlato = zlato;
    }

    public Igrac(String ime, double x, double y) {
        super(x, y, 100, 1, 0);
        this.ime = ime;
        this.inventar = new DeoOpreme[5];
        this.zlato = 10000;
    }

    public Igrac(String ime, int zlato, PokretniEntitet p){
        super(p.getX(), p.getY(), p.getVitalnost(), p.getBrzina(), p.getUgao());
        this.ime = ime;
        this.zlato = zlato;
    }

    public String getIme() {
        return ime;
    }

    public int getZlato() {
        return zlato;
    }

    public void setZlato(int zlato) {
        this.zlato = zlato;
    }

    public DeoOpreme[] getInventar() {
        return inventar;
    }

    private static int i = 0;

    public void kupi(DeoOpreme artikal){
        if(i == 5 || zlato < artikal.getCena())
            return;
        zlato -= artikal.getCena();
        inventar[i] = artikal;
        i++;
    }

    @Override
    public String toString() {
        return "Igrac: " + ime + " (" + zlato + " zlata) ; " + super.toString();
    }
}
