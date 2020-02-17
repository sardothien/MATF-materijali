package instanceOf;

public class Pravougaonik extends Oblik {

    private double a, b;

    public Pravougaonik(Tacka centar, double a, double b) {
        super(centar);
        this.a = a;
        this.b = b;
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    @Override
    public String toString() {
        return "Pravougaonik: a=" + a + ", b=" + b;
    }
}
