import java.util.Arrays;

public class TarotProrok extends Prorok {

    private TarotKarta[] tarotKarta;

    public TarotProrok(String ime, int brOstavarenihProrocanstava, int ukupanBrProrocanstava, TarotKarta[] tarotKarta) {
        super(ime, brOstavarenihProrocanstava, ukupanBrProrocanstava);
        this.tarotKarta = Arrays.copyOf(tarotKarta, tarotKarta.length);
    }

    public TarotProrok(Prorok p, TarotKarta[] tarotKarta) {
        super(p);
        this.tarotKarta = tarotKarta;
    }

    public TarotKarta[] getTarotKarta() {
        return tarotKarta;
    }

    private int i;
    public TarotKarta izvuciKartu(){
        TarotKarta tk = tarotKarta[i];
        i = (i+1) % tarotKarta.length;
        return tk;
    }

    public String proreci(TarotKarta tk){
        String vreme = "sadasnjost";
        if(tk.getVreme() == 1)
            vreme = "buducnost";
        if(tk.getVreme() == -1)
            vreme = "proslost";

        return vreme + " " + tk.getOpis();
    }

    @Override
    public String toString() {
        return "[tarot prorok]: " + super.toString() +
                ", poseduje karata: " + tarotKarta.length;
    }
}
