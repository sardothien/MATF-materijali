public abstract class Program {

    private String ime;
    private double potrebnoMemorije;
    private Platforma platforma;

    public Program(String ime, double potrebnoMemorije, Platforma platforma) {
        this.ime = ime;
        this.potrebnoMemorije = potrebnoMemorije;
        this.platforma = platforma;
    }

    public Program(Program p) {
        this(p.ime, p.potrebnoMemorije, p.platforma);
    }

    public abstract double cenaIzvrsavanja();
    public abstract double memorijskoZauzece();

    public String getIme() {
        return ime;
    }

    public double getPotrebnoMemorije() {
        return potrebnoMemorije;
    }

    public Platforma getPlatforma() {
        return platforma;
    }
}
