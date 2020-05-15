public class KonzolaVideoIgra extends VideoIgra {

    private String platforma; // ps4 ili xbone

    public KonzolaVideoIgra(String ime, String zanr, int cena, String platforma) {
        super(ime, zanr, cena);
        this.platforma = platforma;
    }

    @Override
    public String getPlatforma() {
        return platforma;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
