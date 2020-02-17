public class Poruka {

    private String tekst_poruke;

    public Poruka(String tekst_poruke) {
        this.tekst_poruke = tekst_poruke;
    }

    public String getTekst_poruke() {
        return tekst_poruke;
    }

    public Poruka(Poruka p){
        this(p.tekst_poruke);
    }

    @Override
    public String toString() {
        return "Tajna poruka: " + tekst_poruke;
    }
}
