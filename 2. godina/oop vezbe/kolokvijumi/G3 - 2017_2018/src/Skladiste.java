public class Skladiste extends Prostorija {

    private double preostaloMesta;
    private double dimenzijaPalete;

    public Skladiste(String naziv, double duzina, double sirina, double dimenzijaPalete) {
        super(naziv, duzina, sirina);
        this.preostaloMesta = duzina*sirina;
        this.dimenzijaPalete = dimenzijaPalete;
    }

    public double getPreostaloMesta() {
        return preostaloMesta;
    }

    public double getDimenzijaPalete() {
        return dimenzijaPalete;
    }

    public void setPreostaloMesta(double preostaloMesta) {
        this.preostaloMesta = preostaloMesta;
    }

    public void setDimenzijaPalete(double dimenzijaPalete) {
        this.dimenzijaPalete = dimenzijaPalete;
    }

    public void dodajPalete(int brojPaleta){
        int maxPaleta = (int)(getDuzina()/dimenzijaPalete)*(int)(getSirina()/dimenzijaPalete);
        int popunjenoPaleta = (int)((getDuzina()*getSirina() - preostaloMesta)
        / (dimenzijaPalete*dimenzijaPalete));
        int moze = maxPaleta - popunjenoPaleta;

        if(brojPaleta <= moze) {
            preostaloMesta -= brojPaleta*dimenzijaPalete*dimenzijaPalete;
            System.out.println("Uspesno su smestene sve palete!");
        }
        else if(moze != 0){
            preostaloMesta -= moze*dimenzijaPalete*dimenzijaPalete;
            System.out.println("Uspesno je smesteno " + moze + " od " + brojPaleta + " paleta.");
        }
        else
            System.out.println("Neuspesno smestanje, skladiste je puno!");
    }

    @Override
    public String toString() {
        return "Skladiste " + super.toString() + " (slobodno " + preostaloMesta + "m^2).";
    }
}
