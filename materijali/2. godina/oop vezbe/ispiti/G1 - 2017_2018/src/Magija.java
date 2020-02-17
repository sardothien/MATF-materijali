public class Magija {

    private int snaga;
    private String ime;

    public Magija(int snaga, String ime) {
        this.snaga = snaga;
        this.ime = ime;
    }

    public Magija(Magija m){
        this(m.snaga, m.ime);
    }

    public int getSnaga() {
        return snaga;
    }

    public String getIme() {
        return ime;
    }

    @Override
    public String toString() {
        return ime + " " + snaga;
    }
}
