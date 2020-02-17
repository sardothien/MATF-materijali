public class Muskarac extends Pacijent {

    public Muskarac(double masa, double visina, int starost, Aktivnost dnevnaAktivnost) {
        super(masa, visina, starost, dnevnaAktivnost);
    }

    @Override
    public String pol() {
        return "pacijent";
    }

    @Override
    public double preporuceniDnevniUnosKalorija() {
        return 662 - 9.53*getStarost() + 1.4*(15.91*getMasa() + 539.6*getVisina()/100);
    }

    @Override
    public String toString() {
        return "[" + pol() + "] " + super.toString();
    }
}
