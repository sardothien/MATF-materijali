import java.util.Set;

public class Pesma extends ZabavniSadrzaj {

    private String izvodjac;
    private String zanr;

    public Pesma(String naziv, int duzinaTrajanja, String izvodjac, String zanr) {
        super(naziv, duzinaTrajanja);
        this.izvodjac = izvodjac;
        this.zanr = zanr;
    }

    public String getIzvodjac() {
        return izvodjac;
    }

    public String getZanr() {
        return zanr;
    }

    @Override
    public boolean zaPreporuku(String uslov, int opcija, Set<ZabavniSadrzaj> ocenjenSadrzaj) {
        if (!ocenjenSadrzaj.isEmpty())
            return false;
        else{
            if (opcija == 1)
                return uslov.equals(izvodjac);
            else if(opcija == 2)
                return !uslov.trim().equals("") && zanr.contains(uslov.trim());
            return false;
        }
    }

    @Override
    public String toString() {
        int minuti = getDuzinaTrajanja() / 60;
        int sekunde = getDuzinaTrajanja() % 60;
        return "[pesma] " + getNaziv() + " " + minuti + ":" + sekunde;
    }

    @Override
    public int compareTo(ZabavniSadrzaj o) {
        if (o instanceof Pesma)
            return this.getNaziv().compareTo(o.getNaziv());
        return 1;
    }
}
