public abstract class Predikcija {

    private Osoba osoba;

    public Predikcija(Osoba osoba) {
        this.osoba = osoba;
    }

    public Osoba getOsoba() {
        return osoba;
    }

    public abstract double visina();

    public static double greska(double pravaVisina, double prediktovanaVisina){
        return Math.abs(pravaVisina - prediktovanaVisina);
    }
}
