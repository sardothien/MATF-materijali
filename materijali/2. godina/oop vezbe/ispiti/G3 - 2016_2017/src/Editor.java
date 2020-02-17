public class Editor extends Softver {

    private String najcesciJezik;

    public Editor(String ime, int brojLinija, String programskiJezik, String najcesciJezik) {
        super(ime, brojLinija, programskiJezik);
        this.najcesciJezik = najcesciJezik;
    }

    public String getNajcesciJezik() {
        return najcesciJezik;
    }

    @Override
    public String toString() {
        return "[editor]: " + getIme() + ", " + getBrojLinija() +
                ", " + getProgramskiJezik() + ", " + najcesciJezik;
    }
}
