package Geometrija;

public class Kvadrat extends Pravougaonik {
    public Kvadrat(Tacka c, double a){
        // konstruktor Pravougaonik(Tacka c, double sirina, double visina)
        super(c, a, a);
    }

    public Kvadrat(double x, double y, double a){
        super(x, y, a, a);
    }

    public Kvadrat(double a){
        super(a, a);
    }

    // Konstruktor kopije
    public Kvadrat(Kvadrat k){
        super(k.centar, k.sirina, k.visina);
    }

    public double getDimenzija(){
        return this.sirina;
    }

    public String toString(){
        return "Kvadrat centar = " + centar + " a = " + sirina;
    }
}
