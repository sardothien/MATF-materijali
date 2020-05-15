public abstract class StambeniObjekat {
    private String adresa;

    public StambeniObjekat(String adresa) {
        this.adresa = adresa;
    }

    public String getAdresa() {
        return adresa;
    }

    public void setAdresa(String adresa) {
        this.adresa = adresa;
    }

    public abstract double porez(double cena_po_kvadratu);
}
