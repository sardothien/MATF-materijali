package Geometrija;

public class Krug extends Elipsa {

    public Krug(Tacka c, double r){
        // konstruktor Elipsa(Tacka c, double a, double b)
        super(c, r, r);
    }

    public Krug(double x, double y, double r){
        super(x, y, r, r);
    }

    public Krug(double r){
        super(r, r);
    }

    // Konstruktor kopije
    public Krug(Krug k){
        super(k.centar, k.a, k.a);
    }

    public double getPoluprecnik(){
        return this.a;
    }

    @Override
    public String toString() {
        return "Krug centar = " + centar + " r = " + a;
    }
}
