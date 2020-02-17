package Geometrija;

public class Kvadrat extends Pravougaonik {

    public Kvadrat(Tacka centar, double stranica) {
        super(centar, stranica, stranica);
    }

    public double getDimenzijaStranice(){
        return getSirina();
    }

    @Override
    public String toString() {
        return "Kvadrat{ centar = " + getCentar()
                + " a = " + getSirina() + "}";
    }
}
