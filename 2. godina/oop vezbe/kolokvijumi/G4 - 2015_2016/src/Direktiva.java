public class Direktiva {

    private String ime;
    private String naredba;

    public Direktiva(String ime, String naredba) {
        this.ime = ime;
        this.naredba = naredba;
    }

    public Direktiva(Direktiva d){
        this(d.ime, d.naredba);
    }

    public String getIme() {
        return ime;
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    public String getNaredba() {
        return naredba;
    }

    public void setNaredba(String naredba) {
        this.naredba = naredba;
    }

    @Override
    public String toString() {
        return ime + " je dobio naredbu: \n" +
                naredba;
    }
}
