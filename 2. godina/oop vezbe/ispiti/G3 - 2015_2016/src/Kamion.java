public class Kamion extends Vozilo {

    private double nosivost;

    public Kamion(double tezina, double nosivost) {
        super(tezina);
        this.nosivost = nosivost;
    }

    @Override
    public char vrsta() {
        return 'K';
    }

    public double getTezina(){
        return super.getTezina() + nosivost;
    }
}
