public class PCVideoIgra extends VideoIgra {

    private int zahtevnost; // od 1 do 5

    public PCVideoIgra(String ime, String zanr, int cena, int zahtevnost) {
        super(ime, zanr, cena);
        this.zahtevnost = zahtevnost;
    }

    public int getZahtevnost() {
        return zahtevnost;
    }

    @Override
    public String getPlatforma() {
        return "pc";
    }

    @Override
    public String toString() {
        return super.toString() + " " + zahtevnost + "/5";
    }
}
