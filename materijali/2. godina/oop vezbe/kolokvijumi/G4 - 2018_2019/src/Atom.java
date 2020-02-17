public class Atom {

    private int atomskiBroj;
    private String simbol;
    private int naelektrisanje;
    private int brValentnihE;
    private boolean nemetal;

    public Atom() {
        atomskiBroj = 1;
        simbol = "H";
        brValentnihE = 1;
        nemetal = true;
    }

    public Atom(int atomskiBroj, String simbol, int naelektrisanje, int brValentnihE, boolean nemetal) {
        this.atomskiBroj = atomskiBroj;
        this.simbol = simbol;
        this.naelektrisanje = naelektrisanje;
        this.brValentnihE = brValentnihE;
        this.nemetal = nemetal;
    }

    public Atom(int atomskiBroj, String simbol, int brValentnihE, boolean nemetal) {
        this.atomskiBroj = atomskiBroj;
        this.simbol = simbol;
        this.naelektrisanje = 0;
        this.brValentnihE = brValentnihE;
        this.nemetal = nemetal;
    }

    public Atom(Atom a){
        this(a.atomskiBroj, a.simbol, a.naelektrisanje, a.brValentnihE, a.nemetal);
    }

    public int getAtomskiBroj() {
        return atomskiBroj;
    }

    public String getSimbol() {
        return simbol;
    }

    public int getNaelektrisanje() {
        return naelektrisanje;
    }

    public int getBrValentnihE() {
        return brValentnihE;
    }

    public boolean isNemetal() {
        return nemetal;
    }

    public void setNaelektrisanje(int naelektrisanje) {
        this.naelektrisanje = naelektrisanje;
    }

    public void setBrValentnihE(int brValentnihE) {
        this.brValentnihE = brValentnihE;
    }

    @Override
    public String toString() {
        return simbol;
    }
}
