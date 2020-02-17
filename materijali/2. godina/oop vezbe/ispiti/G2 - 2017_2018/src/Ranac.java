public class Ranac {

    private int maxTezina;
    private int slobodnoTezina;

    public Ranac(int maxTezina) {
        this.maxTezina = maxTezina;
        this.slobodnoTezina = maxTezina;
    }

    public int getMaxTezina() {
        return maxTezina;
    }

    public int getSlobodnoTezina() {
        return slobodnoTezina;
    }

    public boolean smestiDragulj(double tezina){
        if (tezina <= slobodnoTezina){
            slobodnoTezina -= tezina;
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return "ranac: " + slobodnoTezina + "(" + maxTezina + ")";
    }
}
