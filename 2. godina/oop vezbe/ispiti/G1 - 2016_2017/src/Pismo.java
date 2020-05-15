public class Pismo extends Posiljka {

    private boolean preporuceno;

    public Pismo(String imePrezime, int brPoste, boolean preporuceno) {
        super(imePrezime, brPoste);
        this.preporuceno = preporuceno;
    }

    public boolean isPreporuceno() {
        return preporuceno;
    }

    public void setPreporuceno(boolean preporuceno) {
        this.preporuceno = preporuceno;
    }

    @Override
    public String toString() {
        return preporuceno ? super.toString() + " P" : super.toString();
    }
}
