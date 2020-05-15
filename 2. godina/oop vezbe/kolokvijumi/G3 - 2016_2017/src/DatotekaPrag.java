public class DatotekaPrag {

    private String ime, pravaPristupa;

    public DatotekaPrag(String ime, String pravaPristupa) {
        this.ime = ime;
        this.pravaPristupa = pravaPristupa;
    }

    public DatotekaPrag(DatotekaPrag dp){
        this(dp.ime, dp.pravaPristupa);
    }

    public String getIme() {
        return ime;
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    public String getPravaPristupa() {
        return pravaPristupa;
    }

    public void setPravaPristupa(String pravaPristupa) {
        this.pravaPristupa = pravaPristupa;
    }

    @Override
    public String toString() {
        return "Datoteka " + ime + " sa pravima pristupa " + pravaPristupa;
    }
}
