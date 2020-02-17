package Geometrija;

public class Kvadrat extends Pravougaonik {
    public Kvadrat(Tacka centar, double a) {
        super(centar, a, a);
    }

    public double getStranica(){
        return getSirina();
    }

    @Override
    public String toString() {
        return "Kvadrat";
    }
}
