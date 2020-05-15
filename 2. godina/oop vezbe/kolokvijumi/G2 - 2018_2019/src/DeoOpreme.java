public class DeoOpreme extends Entitet {

    private String ime;
    private int cena;
    public static int brojObjekataKlaseDeoOpreme = 0;

    public DeoOpreme(String ime, int cena) {
        this.ime = ime;
        this.cena = cena;
        brojObjekataKlaseDeoOpreme++;
    }

    public DeoOpreme(DeoOpreme d){
        this(d.ime, d.cena);
        brojObjekataKlaseDeoOpreme++;
    }

    public String getIme() {
        return ime;
    }

    public int getCena() {
        return cena;
    }

    public static int getBrojObjekataKlaseDeoOpreme() {
        return brojObjekataKlaseDeoOpreme;
    }

    @Override
    public String toString() {
        return "DeoOpreme: " + ime + " (" + cena + " zlata)";
    }

    public DeoOpreme(double x, double y, int vitalnost, String ime, int cena) {
        super(x, y, vitalnost);
        this.ime = ime;
        this.cena = cena;
    }
}
