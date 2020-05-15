public class SifrarTranslacija extends Sifrar {
    private int pomeraj;

    public SifrarTranslacija(Poruka poruka, int pomeraj) {
        super(poruka);
        this.pomeraj = pomeraj;
    }

    public int getPomeraj() {
        return pomeraj;
    }

    public void setPomeraj(int pomeraj) {
        this.pomeraj = pomeraj;
    }

    @Override
    public String toString() {
        return "Transliraj za " + pomeraj + "\n" +
                "Tajna poruka: " + getPoruka();
    }

    @Override
    public Poruka sifruj() {
        String poruka = getPoruka().getTekst_poruke();
        char[] tekst_poruke = poruka.toCharArray();
        for(int i = 0; i < poruka.length(); i++)
            tekst_poruke[i] += pomeraj;
        return new Poruka(new String(tekst_poruke));
    }
}
