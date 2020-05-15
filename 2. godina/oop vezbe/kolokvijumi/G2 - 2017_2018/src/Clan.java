public class Clan {
    private String imeOsobe;
    private String omiljeniZanr;

    public Clan(String imeOsobe, String omiljeniZanr) {
        this.imeOsobe = imeOsobe;
        this.omiljeniZanr = omiljeniZanr;
    }

    public String getImeOsobe() {
        return imeOsobe;
    }

    public String getOmiljeniZanr() {
        return omiljeniZanr;
    }

    @Override
    public String toString() {
        return "Ime: " + imeOsobe + "; Omiljeni zanr: " + omiljeniZanr;
    }
}
