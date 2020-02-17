public class Kuca extends StambeniObjekat {
    private Stan stan;

    public Kuca(String adresa, Stan stan) {
        super(adresa);
        this.stan = new Stan(stan);
    }

    public Kuca(String adresa, double povrsina, int brStanara) {
        super(adresa);
        stan = new Stan(povrsina, brStanara);
    }

    public Stan getStan() {
        return stan;
    }

    @Override
    public String toString() {
        return "Kuca:\n" +
                "Adresa: " + getAdresa() + '\n' +
                stan.toString();
    }

    @Override
    public double porez(double cena_po_kvadratu) {
        return stan.porez(cena_po_kvadratu);
    }
}
