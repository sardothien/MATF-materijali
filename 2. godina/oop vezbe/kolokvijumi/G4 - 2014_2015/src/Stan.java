public class Stan {
    private double povrsina;
    private int brStanara;

    public Stan(double povrsina, int brStanara) {
        this.povrsina = povrsina;
        this.brStanara = brStanara;
    }

    public Stan(Stan s){
        this(s.povrsina, s.brStanara);
    }

    public double getPovrsina() {
        return povrsina;
    }

    public void setPovrsina(double povrsina) {
        this.povrsina = povrsina;
    }

    public int getBrStanara() {
        return brStanara;
    }

    public void setBrStanara(int brStanara) {
        this.brStanara = brStanara;
    }

    public double porez(double cena_po_kvadratu){
        if(brStanara <= 2)
            return povrsina*cena_po_kvadratu;
        else
            return povrsina*cena_po_kvadratu*(1-(brStanara-2)*0.05);
    }

    @Override
    public String toString() {
        return "Povrsina stana je " + povrsina + "m^2.\n"
                + "Broj stanara je " + brStanara + ".";
    }
}
