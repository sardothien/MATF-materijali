import java.util.Arrays;

public class Zgrada extends StambeniObjekat {
    private Stan[] stanovi;

    public Zgrada(String adresa, Stan[] stanovi) {
        super(adresa);
        this.stanovi = new Stan[stanovi.length];
        for (int i = 0; i < stanovi.length; i++)
            this.stanovi[i] = new Stan(stanovi[i]);
    }

    @Override
    public String toString() {
        String rez = "Zgrada:\nAdresa: " + getAdresa() + "\n";
        for (int i = 0; i < stanovi.length; i++) {
            rez += (i+1) + ". stan:\n" + stanovi[i].toString() + '\n';
        }
        return rez;
    }

    @Override
    public double porez(double cena_po_kvadratu) {
        double porez = 0;
        for (int i = 0; i < stanovi.length; i++) {
            porez += stanovi[i].porez(cena_po_kvadratu);
        }
        return porez;
    }
}
