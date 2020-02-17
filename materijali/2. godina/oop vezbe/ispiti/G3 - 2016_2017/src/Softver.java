public abstract class Softver {

    private String ime;
    private int brojLinija;
    private String programskiJezik;

    public Softver(String ime, int brojLinija, String programskiJezik) {
        this.ime = ime;
        this.brojLinija = brojLinija;
        this.programskiJezik = programskiJezik;
    }

    public String getIme() {
        return ime;
    }

    public int getBrojLinija() {
        return brojLinija;
    }

    public String getProgramskiJezik() {
        return programskiJezik;
    }
}
