public class Zivotinja {

    private String ime;

    public Zivotinja(String ime) {
        this.ime = ime;
    }

    public Zivotinja(Zivotinja z){
        this(z.ime);
    }

    public String getIme() {
        return ime;
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    @Override
    public String toString() {
        return "";
    }
}
