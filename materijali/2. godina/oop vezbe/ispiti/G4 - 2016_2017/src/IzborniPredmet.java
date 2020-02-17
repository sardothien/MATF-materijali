public class IzborniPredmet extends Predmet {

    private char blok; // M ili R

    public IzborniPredmet(String sifra, String naziv, int godina, int bodovi, char blok) {
        super(sifra, naziv, godina, bodovi);
        this.blok = blok;
    }

    public char getBlok() {
        return blok;
    }

    @Override
    public String toString() {
        String str = blok == 'M' ? "matematika" : "racunarstvo";
        return super.toString() + "\n" + "izborni blok - " + str;
    }

    public int compareTo(Predmet o) {
        if(o == null)
            return 1;
        int rez = Integer.compare(this.getGodina(), o.getGodina());
        if(rez == 0) {
            if(o instanceof ObavezanPredmet)
                return 1;
            else {
                IzborniPredmet op = (IzborniPredmet)o;
                if(blok == 'M' && op.blok == 'R')
                    return -1;
                else if(blok == 'R' && op.blok == 'M')
                    return 1;
                else {
                    int rez1 = Integer.compare(op.getBodovi(), this.getBodovi());
                    if(rez1 == 0)
                        return this.getNaziv().compareTo(op.getNaziv());
                    else return rez1;
                }
            }
        }
        else
            return rez;
    }
}
