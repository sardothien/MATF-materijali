public class Platforma {

    private String ime;
    private double brInstrukcijaZaUcitavanjeProcesa;
    private double memorijaZaProces;

    public Platforma(String ime, double brInstrukcijaZaUcitavanjeProcesa, double memorijaZaProces) {
        this.ime = ime;
        this.brInstrukcijaZaUcitavanjeProcesa = brInstrukcijaZaUcitavanjeProcesa;
        this.memorijaZaProces = memorijaZaProces;
    }

    public Platforma(Platforma p){
        this(p.ime, p.brInstrukcijaZaUcitavanjeProcesa, p.memorijaZaProces);
    }

    public String getIme() {
        return ime;
    }

    public double getBrInstrukcijaZaUcitavanjeProcesa() {
        return brInstrukcijaZaUcitavanjeProcesa;
    }

    public double getMemorijaZaProces() {
        return memorijaZaProces;
    }

    public void setBrInstrukcijaZaUcitavanjeProcesa(double brInstrukcijaZaUcitavanjeProcesa) {
        this.brInstrukcijaZaUcitavanjeProcesa = brInstrukcijaZaUcitavanjeProcesa;
    }

    @Override
    public String toString() {
        return "- " + ime + " broj instrukcija za ucitavanje procesa" +
                "=" + brInstrukcijaZaUcitavanjeProcesa + " memorija za" +
                "proces=" + memorijaZaProces + "MB";
    }
}
