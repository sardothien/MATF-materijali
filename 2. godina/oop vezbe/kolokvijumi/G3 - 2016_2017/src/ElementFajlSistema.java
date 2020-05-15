public abstract class ElementFajlSistema {

    String ime, pravaPristupa;

    public ElementFajlSistema(String ime, String pravaPristupa) {
        this.ime = ime;
        this.pravaPristupa = pravaPristupa;
    }

    public String getIme() {
        return ime;
    }

    public String getPravaPristupa() {
        return pravaPristupa;
    }

    public abstract void ispisiSadrzaj();
    public abstract boolean jeDatoteka();
    public abstract boolean jeDirektorijum();

    public void promeniPrava(String s){
        this.pravaPristupa = s;
    }

    @Override
    public String toString() {
        return ime + " " + pravaPristupa;
    }
}
