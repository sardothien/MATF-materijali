public abstract class Predmet implements Comparable<Predmet> {

    private String sifra;
    private String naziv;
    private int godina;
    private int brSemestara;
    private int bodovi;

    public Predmet(String sifra, String naziv, int godina, int brSemestara, int bodovi) {
        this.sifra = sifra;
        this.naziv = naziv;
        this.godina = godina;
        this.brSemestara = brSemestara;
        this.bodovi = bodovi;
    }

    public Predmet(String sifra, String naziv, int godina, int bodovi) {
        this.sifra = sifra;
        this.naziv = naziv;
        this.godina = godina;
        this.brSemestara = 1;
        this.bodovi = bodovi;
    }

    public String getSifra() {
        return sifra;
    }

    public String getNaziv() {
        return naziv;
    }

    public int getGodina() {
        return godina;
    }

    public int getBrSemestara() {
        return brSemestara;
    }

    public int getBodovi() {
        return bodovi;
    }

    @Override
    public String toString() {
        return "[ " + sifra + " - " + naziv + "] godina: " + godina +
                ", semestar: " + brSemestara + ", ESPB: " + bodovi;
    }
}
