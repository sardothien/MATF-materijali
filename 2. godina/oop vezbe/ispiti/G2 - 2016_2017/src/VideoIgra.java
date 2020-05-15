public abstract class VideoIgra {

    private String ime;
    private String zanr;
    private int cena;

    public abstract String getPlatforma();

    public VideoIgra(String ime, String zanr, int cena) {
        this.ime = ime;
        this.zanr = zanr;
        this.cena = cena;
    }

    public String getIme() {
        return ime;
    }

    public String getZanr() {
        return zanr;
    }

    public int getCena() {
        return cena;
    }

    @Override
    public String toString() {
        return "[" + getPlatforma() + "]: ime: " + getIme() +
                " zanr: " + getZanr() + " cena: " + getCena();
    }
}
