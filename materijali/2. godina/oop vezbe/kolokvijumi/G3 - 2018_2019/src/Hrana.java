public abstract class Hrana implements BivaBacen {

    private double tezina;
    private double domet;

    public Hrana() {
        tezina = 0;
        domet = 0;
    }

    public Hrana(double tezina, double domet) {
        this.tezina = tezina > 0 ? tezina : 0;
        this.domet = domet > 0 ? domet : 0;
    }

    public double getTezina() {
        return tezina;
    }

    public double getDomet() {
        return domet;
    }

    @Override
    public String toString() {
        return "tezina: " + tezina + "g, domet: " + domet + "m";
    }
}
