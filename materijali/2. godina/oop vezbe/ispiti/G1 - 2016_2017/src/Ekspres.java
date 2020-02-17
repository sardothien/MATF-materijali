public class Ekspres extends Posiljka {

    private EkspresUsluga tip;

    public Ekspres(String imePrezime, int brPoste, EkspresUsluga tip) {
        super(imePrezime, brPoste);
        this.tip = tip;
    }

    public EkspresUsluga getTip() {
        return tip;
    }

    @Override
    public String toString() {
        return super.toString() + " " + tip;
    }
}
