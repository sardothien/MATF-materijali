package Geometrija;

public class Elipsa extends Oblik {

    protected double a, b; // poluose

    public Elipsa(Tacka centar, double a, double b){
        super(centar);
        init(a, b);
    }

    public Elipsa(double x, double y, double a, double b){
        super(x, y);
        init(a, b);
    }

    public Elipsa(double a, double b){
        super();
        init(a, b);
    }

    // Konstruktor kopije
    public Elipsa(Elipsa e){
        super(e.centar);
        init(e.a, e.b);
    }

    private void init(double a, double b){
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
        return "Elipsa{" +
                "a=" + a +
                ", b=" + b +
                '}';
    }
}
