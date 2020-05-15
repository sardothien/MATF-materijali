package Geometrija;

public class Pravougaonik extends Oblik implements Obim, Povrsina {

    private double sirina, visina;

    public Pravougaonik(Tacka centar, double sirina, double visina) {
        super(centar);
        this.sirina = sirina;
        this.visina = visina;
    }

    public Pravougaonik() {
        this(new Tacka(), 10, 20);
    }

    public double getSirina() {
        return sirina;
    }

    public double getVisina() {
        return visina;
    }

    @Override
    public double getObim() {
        return 2*sirina + 2*visina;
    }

    @Override
    public double getPovrsina() {
        return sirina*visina;
    }

    @Override
    public String toString() {
        return "Pravougaonik";
    }
}
