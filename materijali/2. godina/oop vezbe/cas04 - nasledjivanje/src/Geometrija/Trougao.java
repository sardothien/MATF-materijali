package Geometrija;

public class Trougao extends Oblik {
    private Tacka a, b, c;

    public Trougao(Tacka centar, Tacka a, Tacka b, Tacka c){
        super(centar);
        init(a, b, c);
    }

    public Trougao(Tacka a, Tacka b, Tacka c){
        super();
        init(a, b, c);
    }

    public Trougao(Tacka centar, double a1, double a2, double b1, double b2, double c1, double c2){
        super(centar);
        init(a1, a2, b1, b2, c1, c2);
    }

    public Trougao(double a1, double a2, double b1, double b2, double c1, double c2){
        this(0, 0, a1, a2, b1, b2, c1, c2);
    }

    public Trougao(double x1, double x2, double a1, double a2, double b1, double b2, double c1, double c2){
        super(x1, x2);
        init(a1, a2, b1, b2, c1, c2);
    }

    public Tacka getA(){
        return a;
    }

    public Tacka getB() {
        return b;
    }

    public Tacka getC() {
        return c;
    }

    public double getAB(){
        return a.distance(b);
    }

    public double getBC(){
        return b.distance(c);
    }

    public double getCA(){
        return c.distance(a);
    }

    private void init(double a1, double a2, double b1, double b2, double c1, double c2){
        this.a = new Tacka(a1, a2);
        this.b = new Tacka(b1, b2);
        this.c = new Tacka(c1, c2);
    }

    private void init(Tacka a, Tacka b, Tacka c){
        this.a = new Tacka(a);
        this.b = new Tacka(b);
        this.c = new Tacka(c);
    }

    @Override
    public String toString(){
        return "Trougao a = " + a + " b = " + b + " c = " + c;
    }
}
