public abstract class Vozilo {

    private static int ukID = 0;
    private final int id = ++ukID;

    private double tezina;

    public Vozilo(double tezina) {
        this.tezina = tezina;
    }

    public double getTezina() {
        return tezina;
    }

    public abstract char vrsta();

    public String toString() {
        return vrsta() + "_" + id + " [" + getTezina() + "]";
    }
}
