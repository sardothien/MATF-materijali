public abstract class RelacijaIncidencije {

    private Prava p;

    public RelacijaIncidencije(Prava p) {
        this.p = p;
    }

    public Prava getP() {
        return p;
    }

    public abstract boolean odnos();
    public abstract double izracunaj();

    @Override
    public String toString() {
        return "p: " + p.toString();
    }
}
