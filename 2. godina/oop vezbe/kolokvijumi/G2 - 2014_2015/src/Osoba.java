public abstract class Osoba {

    private String ime;
    private char pol;

    public Osoba(String ime, char pol) {
        this.ime = ime;
        this.pol = pol;
    }

    public String getIme() {
        return ime;
    }

    public char getPol() {
        return pol;
    }

    public abstract int brojGodinaOsobe(Datum danasnji_datum);

}
