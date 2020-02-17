public class Clan {

    private String ime;
    private int tezina, visina;
    int brojClanova = 0;

    public Clan(String ime, int tezina, int visina) {
        this.ime = ime;
        this.tezina = tezina;
        this.visina = visina;
        brojClanova++;
    }

    public Clan(Clan c){
        this(c.ime, c.tezina, c.visina);
        brojClanova++;
    }

    public String getIme() {
        return ime;
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    public int getTezina() {
        return tezina;
    }

    public void setTezina(int tezina) {
        this.tezina = tezina;
    }

    public int getVisina() {
        return visina;
    }

    public void setVisina(int visina) {
        this.visina = visina;
    }

    public double itm(){
        return (tezina*10000) / (visina*visina);
    }

    public String program(){
        if(itm() > 25)
            return "Kardio";
        else
            return "Individualni";
    }

    @Override
    public String toString() {
        return "Ime: " + ime + '\n' +
                "Visina: " + visina + '\n' +
                "Tezina: " + tezina;
    }
}
