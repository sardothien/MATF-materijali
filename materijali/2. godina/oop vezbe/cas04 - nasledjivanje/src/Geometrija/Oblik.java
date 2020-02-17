package Geometrija;

public class Oblik {

    // protected - mozemo da mu pristupimo iz podklasa
    protected Tacka centar;

    // Konstruktor
    public Oblik(Tacka c){
        centar = new Tacka(c);
    }

    // Konstruktor kopije
    public Oblik(Oblik o){
        this(o.centar);
    }

    public Oblik(double x, double y){
        centar = new Tacka(x, y);
    }

    public Oblik(){
        centar = new Tacka();
    }

    public Tacka getCentar(){
        return centar;
    }

    public String toString(){
        return "Oblik centar = " + centar.toString();
    }
}
