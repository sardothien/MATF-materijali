public class PravaIPrava extends RelacijaIncidencije {

    private Prava q;

    public PravaIPrava(Prava p, Prava q) {
        super(p);
        this.q = q;
    }

    public Prava getQ() {
        return q;
    }

    @Override
    public boolean odnos() {
        double a = super.getP().getA();
        double b = super.getP().getB();
        if(super.getP().vrednostKoeficijenta(a,b) != q.vrednostKoeficijenta(q.getA(), q.getB()))
            return true;
        return false;
    }

    @Override
    public double izracunaj() {
        double k1 = super.getP().vrednostKoeficijenta(super.getP().getA(), super.getP().getB());
        double k2 = q.vrednostKoeficijenta(q.getA(), q.getB());
        if(k1 != k2)
            return Math.toDegrees(Math.atan(Math.abs((k1-k2)/(1+k1*k2))));
        return 0;
    }

    @Override
    public String toString() {
        return super.toString() + " q: " + q.getA() + "*x + " + q.getB()
                + "*y + " + q.getC() + " = 0";
    }
}
