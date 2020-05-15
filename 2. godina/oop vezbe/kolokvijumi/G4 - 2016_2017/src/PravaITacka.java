public class PravaITacka extends RelacijaIncidencije {

    private double x, y;

    public PravaITacka(Prava p, double x, double y) {
        super(p);
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }


    @Override
    public boolean odnos() {
        return (super.getP().getA()*x + super.getP().getB()*y + super.getP().getC() == 0);
    }

    @Override
    public double izracunaj() {
        double a = super.getP().getA();
        double b = super.getP().getB();
        double c = super.getP().getC();
        double d = Math.abs(a*x + b*y + c) /
                   Math.sqrt(a*a + b*b);
        return d;
    }

    @Override
    public String toString() {
        return super.toString() + " T: (" + x + ", " + y + ")";
    }
}
