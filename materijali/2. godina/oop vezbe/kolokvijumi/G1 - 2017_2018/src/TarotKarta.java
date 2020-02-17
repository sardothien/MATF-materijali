public class TarotKarta {

    private int vreme;
    private String opis;
    private String poreklo;

    public TarotKarta(int vreme, String opis, String poreklo) {
        this.vreme = (vreme != 0 && vreme != -1 && vreme != 1) ? 0 : vreme;
        this.opis = opis;
        this.poreklo = poreklo;
    }

    public TarotKarta(TarotKarta tk){
        this(tk.vreme, tk.opis, tk.poreklo);
    }

    public int getVreme() {
        return vreme;
    }

    public String getOpis() {
        return opis;
    }

    public String getPoreklo() {
        return poreklo;
    }

    @Override
    public String toString() {
        String vremeString = "";
        if(vreme == -1)
            vremeString = "proslost";
        if(vreme == 1)
            vremeString = "buducnost";
        if(vreme == 0)
            vremeString = "sadasnjost";

        return "[tarot karta] " +
                "vreme: " + vremeString +
                ", opis: " + opis +
                ", poreklo: " + poreklo;
    }
}
