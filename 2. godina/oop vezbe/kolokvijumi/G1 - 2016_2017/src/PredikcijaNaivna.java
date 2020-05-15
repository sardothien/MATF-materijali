public class PredikcijaNaivna extends Predikcija {

    private int uvecanje;

    public PredikcijaNaivna(Osoba osoba, int uvecanje) {
        super(osoba);
        this.uvecanje = uvecanje;
    }

    public int getUvecanje() {
        return uvecanje;
    }


    @Override
    public double visina() {
        if(getOsoba().getPol() == 'm')
            return 1.2*getOsoba().getTezina() + uvecanje;
        else
            return 0.8*getOsoba().getTezina() + uvecanje;
    }

    @Override
    public String toString() {
            return "Naivna predikcija:" + '\n' +
                    "m: visina = 1.2*tezina + " + uvecanje + '\n' +
                    "z: visina = 0.8*tezina + " + uvecanje;
    }
}
