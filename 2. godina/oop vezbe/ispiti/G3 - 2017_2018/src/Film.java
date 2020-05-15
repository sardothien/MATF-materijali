import java.util.Set;

public class Film extends ZabavniSadrzaj {

    private String glumac; // ime i prezime
    private int godina; // premijera filma

    public Film(String naziv, int duzinaTrajanja, String glumac, int godina) {
        super(naziv, duzinaTrajanja);
        this.glumac = glumac;
        this.godina = godina;
    }

    public String getGlumac() {
        return glumac;
    }

    public int getGodina() {
        return godina;
    }

    @Override
    public boolean zaPreporuku(String uslov, int opcija, Set<ZabavniSadrzaj> ocenjenSadrzaj) {
        if (!ocenjenSadrzaj.isEmpty()){
            return false;
        }
        else{
            if (opcija == 1)
                return uslov.equals(glumac);
            else if (opcija == 2)
                return godina == Integer.parseInt(uslov);
            return false;
        }
    }

    @Override
    public String toString() {
        int sati = getDuzinaTrajanja() / 60;
        int minuti = getDuzinaTrajanja() % 60;
        return "[film] " + getNaziv() + " " + sati + ":" + minuti;
    }

    @Override
    public int compareTo(ZabavniSadrzaj o) {
        if (o instanceof Film)
            return this.getNaziv().compareTo(o.getNaziv());
        else
            return -1;
    }
}
