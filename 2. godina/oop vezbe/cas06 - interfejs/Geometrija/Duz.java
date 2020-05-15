package Geometrija;

public class Duz extends Oblik{

    private Tacka a, b;

    public Duz(Tacka a, Tacka b) {
        super(new Tacka((a.getX()+b.getX())/2, (a.getY()+a.getY())/2));
        this.a = a;
        this.b = b;
    }

    @Override
    public String toString() {
        return "Duz";
    }

    public Tacka getA() {
        return a;
    }

    public Tacka getB() {
        return b;
    }
}
