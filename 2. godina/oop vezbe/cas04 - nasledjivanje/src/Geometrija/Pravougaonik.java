package Geometrija;

public class Pravougaonik extends Oblik {
    protected double sirina, visina;

    public Pravougaonik(Tacka centar, double sirina, double visina){
        /* Uvek pri nasledjivanju pozivamo konstruktor nadklase.
         * super je referenca na nadklasu (Oblik). */
        // Poziva konstruktor Oblik(Tacka c)
        super(centar);
        // Koristimo privatnu fju za inicijalizaciju
        init(sirina, visina);
    }

    public Pravougaonik(double x, double y, double sirina, double visina){
        super(x, y);
        init(sirina, visina);
    }

    public Pravougaonik(double sirina, double visina){
        super();
        init(sirina, visina);
    }

    // Konstruktor kopije
    public Pravougaonik(Pravougaonik p){
        super(p.centar);
        init(p.sirina, p.visina);
    }

    private void init(double sirina, double visina){
        this.sirina = sirina;
        this.visina = visina;
    }

    public double getSirina() {
        return sirina;
    }

    public double getVisina() {
        return visina;
    }

    @Override
    public String toString() {
        return "Pravougaonik{" +
                "sirina=" + sirina +
                ", visina=" + visina +
                '}';
    }
}
