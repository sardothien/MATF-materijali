package Geometrija;

public class Krug extends Elipsa {

    public Krug(Tacka centar, double r) {
        super(centar, r, r);
    }

    public Krug(double r) {
        super(r, r);
    }

    public double getR(){
        return getA();
    }

    @Override
    public String toString() {
        return "Krug{ centar = " + getCentar() +
                " r = " + getR() + "}";
    }
}
