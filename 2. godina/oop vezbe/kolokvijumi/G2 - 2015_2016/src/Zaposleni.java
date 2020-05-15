public class Zaposleni extends Dosije {
    protected int radnoVreme;
    public Zaposleni(String imeIPrezime, String jmbg, int radnoVreme) {
        super(imeIPrezime, jmbg);
        this.radnoVreme = radnoVreme;
    }
}
