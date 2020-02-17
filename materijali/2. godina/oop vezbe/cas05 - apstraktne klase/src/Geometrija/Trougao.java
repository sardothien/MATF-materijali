package Geometrija;

public class Trougao extends Oblik{
    private Tacka a, b, c;

    public Trougao(Tacka centar, Tacka a, Tacka b, Tacka c){
        super(centar);
        init(a, b, c);
    }

    public Trougao(Tacka a, Tacka b, Tacka c) {
        super();
        init(a, b, c);
    }

    public Tacka getA() {
        return a;
    }

    public Tacka getB() {
        return b;
    }

    public Tacka getC() {
        return c;
    }

    private void init(Tacka a, Tacka b, Tacka c){
        this.a = new Tacka(a);
        this.b = new Tacka(b);
        this.c = new Tacka(c);
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

    @Override
    public double getObim() {
        return getAB() + getBC() + getCA();
    }

    @Override
    public double getPovrsina() {
        double s = getObim()/2;
        return Math.sqrt(s*(s-getAB())*(s-getBC())*(s-getCA()));
    }

    @Override
    public String toString() {
        return "Trougao{" +
                "centar = " + getCentar() +
                ", a=" + a +
                ", b=" + b +
                ", c=" + c +
                '}';
    }
}
