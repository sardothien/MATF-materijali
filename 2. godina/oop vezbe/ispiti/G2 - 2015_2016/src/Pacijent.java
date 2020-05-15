public abstract class Pacijent implements Comparable<Pacijent>{

    private double masa, visina; // T, V
    private int starost; // G
    private Aktivnost dnevnaAktivnost;  // PA

    public Pacijent(double masa, double visina, int starost, Aktivnost dnevnaAktivnost) {
        this.masa = masa;
        this.visina = visina;
        this.starost = starost;
        this.dnevnaAktivnost = dnevnaAktivnost;
    }

    public double getMasa() {
        return masa;
    }

    public double getVisina() {
        return visina;
    }

    public int getStarost() {
        return starost;
    }

    public Aktivnost getDnevnaAktivnost() {
        return dnevnaAktivnost;
    }

    public abstract String pol();
    public abstract double preporuceniDnevniUnosKalorija();

    @Override
    public int compareTo(Pacijent o) {
        int rez = Integer.compare(this.starost, o.starost);
        return rez == 0
             ? Double.compare(this.preporuceniDnevniUnosKalorija(), o.preporuceniDnevniUnosKalorija())
             : rez;
    }

    @Override
    public String toString() {
        return "masa: " + masa + "kg, visina: " + visina + "cm, starost: "
                + starost + " god\nnivo aktivnosti: "
                + dnevnaAktivnost + ", preporuceni dnevni unos kalorija: "
                + preporuceniDnevniUnosKalorija()
                + "\n-----------------------------------------------------";
    }
}
