public class Biblioteka extends Softver {

    private String opis;

    public Biblioteka(String ime, int brojLinija, String programskiJezik, String opis) {
        super(ime, brojLinija, programskiJezik);
        this.opis = opis;
    }

    public String getOpis() {
        return opis;
    }

    @Override
    public String toString() {
        return "[biblioteka]: " + getIme() + ", " + getBrojLinija() +
                ", " + getProgramskiJezik() + ", " + opis;
    }
}
