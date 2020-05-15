package instanceOf;

public class Krug extends Oblik {

    private double r;

    public Krug(Tacka centar, double r) {
        super(centar);
        this.r = r;
    }

    public double getR() {
        return r;
    }

    @Override
    public String toString() {
        return "Krug: r=" + r;
    }
}
