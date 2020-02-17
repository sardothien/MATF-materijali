public class Podatak {

    private int visina, tezina;
    private Pol pol;

    public int getVisina() {
        return visina;
    }

    public int getTezina() {
        return tezina;
    }

    public Pol getPol() {
        return pol;
    }

    public Podatak(int visina, int tezina, Pol pol) {
        this.visina = visina;
        this.tezina = tezina;
        this.pol = pol;
    }

    @Override
    public String toString() {
        return visina + " " + tezina + " " + pol;
    }
}
