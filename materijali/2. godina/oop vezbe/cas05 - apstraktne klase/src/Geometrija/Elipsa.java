package Geometrija;

public class Elipsa extends Oblik {
    private double a, b;

    public Elipsa(Tacka centar, double a, double b) {
        super(centar);
        this.a = a;
        this.b = b;
    }

    public Elipsa(double a, double b) {
        super();
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
    public double getObim() {
        double h = ((a-b)*(a-b))/((a+b)*(a+b));
        return Math.PI * (a+b) * (1 + 1/4*h + 1/64*h*h + 1/256*h*h*h);
    }

    @Override
    public double getPovrsina() {
        return a*b*Math.PI;
    }

    @Override
    public String toString() {
        return "Elipsa{ c = " + getCentar() +
                " a=" + a +
                ", b=" + b +
                '}';
    }
}
