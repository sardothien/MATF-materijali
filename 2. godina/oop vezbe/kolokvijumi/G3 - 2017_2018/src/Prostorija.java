public class Prostorija {
    private String naziv;
    private double duzina;
    private double sirina;

    public Prostorija(String naziv, double duzina, double sirina) {
        this.naziv = naziv;
        this.duzina = duzina;
        this.sirina = sirina;
    }

    public String getNaziv() {
        return naziv;
    }

    public double getDuzina() {
        return duzina;
    }

    public double getSirina() {
        return sirina;
    }

    @Override
    public String toString() {
        return naziv + " povrsine " + duzina*sirina + "m^2";
    }
}
