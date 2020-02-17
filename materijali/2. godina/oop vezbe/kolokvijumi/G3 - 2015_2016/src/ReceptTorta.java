public class ReceptTorta extends Recept {
    private int nivoTezine;

    public ReceptTorta(Sastojak[] sastojci, int nivoTezine) {
        super(sastojci);
        this.nivoTezine = (nivoTezine < 1 || nivoTezine > 5) ? 3 : nivoTezine;
    }

    public String tezinaRecepta(){
        switch (nivoTezine){
            case 1: return "lak";
            case 2: return "srednje lak";
            case 3: return "srednji";
            case 4: return "srednje tezak";
            case 5: return "tezak";
        }
        return null;
    }

    public int getNivoTezine() {
        return nivoTezine;
    }

    public double ukupnaMasaTorte(){
        double masa = 0;
        Sastojak[] s = super.getSastojci();
        for (int i = 0; i < s.length; i++)
            if (s[i].getJedinicaMere().equalsIgnoreCase("g"))
                masa += s[i].getKolicina();
        return masa;
    }
}
