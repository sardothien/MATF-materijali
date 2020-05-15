public class Autobus extends Vozilo {

    private int kapacitet;

    public Autobus(double tezina, int kapacitet) {
        super(tezina);
        this.kapacitet = kapacitet;
    }

    @Override
    public char vrsta() {
        return 'A';
    }

    public double getTezina(){
        return super.getTezina() + kapacitet*110;
    }
}
