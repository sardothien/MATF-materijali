public abstract class Posiljka implements Comparable<Posiljka>{

    private int id;
    private String imePrezime;
    private int brPoste;
    private boolean statusPosiljke;  // false - PRIJEM, true - OTPREMA

    public Posiljka(String imePrezime, int brPoste) {
        this.id = vratiSledeciID();
        this.imePrezime = imePrezime;
        this.brPoste = brPoste;
        this.statusPosiljke = false;
    }

    public int getId() {
        return id;
    }

    public String getImePrezime() {
        return imePrezime;
    }

    public int getBrPoste() {
        return brPoste;
    }

    public boolean isStatusPosiljke() {
        return statusPosiljke;
    }

    public void setStatusPosiljke(boolean statusPosiljke) {
        this.statusPosiljke = statusPosiljke;
    }

    private static int tekuciID = 1;

    public int vratiSledeciID(){
        return tekuciID++;
    }

    @Override
    public int compareTo(Posiljka o) {
        int rez = Integer.compare(getBrPoste(), o.getBrPoste());
        if (rez == 0)
            return getImePrezime().compareTo(o.getImePrezime());
        return rez;
    }

    @Override
    public String toString() {
        String status = statusPosiljke ? "OTPREMA" : "PRIJEM";
        return id + " [" + status + "] " + imePrezime + " "
                + brPoste;
    }
}
