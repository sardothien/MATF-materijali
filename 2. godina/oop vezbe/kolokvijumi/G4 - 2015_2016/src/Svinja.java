public class Svinja extends Zivotinja {
    private String parola;

    public Svinja(String ime, String parola) {
        super(ime);
        this.parola = parola;
    }

    public Svinja(String ime) {
        super(ime);
        parola = "Sve su zivotinje jednake";
    }

    public Svinja(Zivotinja z, String parola) {
        super(z);
        this.parola = parola;
    }

    public String getParola() {
        return parola;
    }

    public void setParola(String parola) {
        this.parola = parola;
    }

    @Override
    public String toString() {
        return "Svinja " + getIme() + " kaze: " + parola;
    }
}
