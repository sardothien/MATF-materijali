public class SIfraRotacija extends Sifrar {

    private int br_mesta;
    private String smer;

    public SIfraRotacija(Poruka poruka, int br_mesta, String smer) {
        super(poruka);
        this.br_mesta = br_mesta;
        this.smer = smer;
    }

    public int getBr_mesta() {
        return br_mesta;
    }

    public void setBr_mesta(int br_mesta) {
        this.br_mesta = br_mesta;
    }

    public String getSmer() {
        return smer;
    }

    public void setSmer(String smer) {
        this.smer = smer;
    }

    @Override
    public String toString() {
        return "Rotiraj u smeru " + smer + " za " + br_mesta + ":\n" +
                getPoruka();
    }

    @Override
    public Poruka sifruj() {
        StringBuffer sb = new StringBuffer(getPoruka().getTekst_poruke());
        if(smer.equalsIgnoreCase("levo")){
            for (int i = 0; i < br_mesta; i++) {
                sb.append(sb.charAt(0));
                sb.deleteCharAt(0);
            }
        }
        else if(smer.equalsIgnoreCase("desno")){
            for (int i = 0; i < br_mesta; i++) {
                sb.insert(0, sb.charAt(sb.length()-1));
                sb.deleteCharAt(sb.length()-1);
            }
        }
        return new Poruka(sb.toString());
    }
}
