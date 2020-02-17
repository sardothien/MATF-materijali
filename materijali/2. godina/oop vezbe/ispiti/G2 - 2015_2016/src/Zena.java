public class Zena extends Pacijent {

    public Zena(double masa, double visina, int starost, Aktivnost dnevnaAktivnost) {
        super(masa, visina, starost, dnevnaAktivnost);
    }

    @Override
    public String pol() {
        return "pacijentkinja";
    }

    @Override
    public double preporuceniDnevniUnosKalorija() {
        return 354 - 6.91*getStarost() + 1.2*(9.36*getMasa() + 726*getVisina()/100);
    }

    @Override
    public String toString() {
        return "[" + pol() + "] " + super.toString();
    }
}
