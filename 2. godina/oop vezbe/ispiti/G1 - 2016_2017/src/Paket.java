public class Paket extends Posiljka {

    private String sadrzaj;

    public Paket(String imePrezime, int brPoste, String sadrzaj) {
        super(imePrezime, brPoste);
        this.sadrzaj = sadrzaj;
    }

    public String getSadrzaj() {
        return sadrzaj;
    }

    @Override
    public String toString() {
        return super.toString() + " " + sadrzaj;
    }
}
