package IzrazKloniranje;

public class Broj extends Izraz {
    private double vrednost;

    public Broj(double vrednost) {
        this.vrednost = vrednost;
    }

    // Konstruktor kopije
    public Broj(Broj b) {
        this.vrednost = b.vrednost;
    }


    @Override
    public double izracunaj() {
        return vrednost;
    }

    @Override
    public Izraz klon() {
        return new Broj(this); // koristimo konstr. kopije
    }

    public double getVrednost() {
        return vrednost;
    }

    @Override
    public String toString() {
        return "" + vrednost;
    }
}
