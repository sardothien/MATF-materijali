public class Sastojak {

    private String naziv;
    private double kolicina;
    private String jedinicaMere;

    private static String[] dozvoljeniNazivi = {
      "jaje", "brasno", "secer", "puter"
    };

    public Sastojak(String naziv, double kolicina, String jedinicaMere) {
        this.naziv = naziv;
        this.kolicina = kolicina;
        this.jedinicaMere = jedinicaMere;
    }

    public Sastojak(Sastojak s){
        this(s.naziv, s.kolicina, s.jedinicaMere);
    }

    public String getNaziv() {
        return naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv = naziv;
    }

    public double getKolicina() {
        return kolicina;
    }

    public void setKolicina(double kolicina) {
        this.kolicina = kolicina;
    }

    public String getJedinicaMere() {
        return jedinicaMere;
    }

    public void setJedinicaMere(String jedinicaMere) {
        this.jedinicaMere = jedinicaMere;
    }

    public static boolean dozvoljenSastojak(String naziv){
        if(!naziv.equalsIgnoreCase(dozvoljeniNazivi[0])
        && !naziv.equalsIgnoreCase(dozvoljeniNazivi[1])
        && !naziv.equalsIgnoreCase(dozvoljeniNazivi[2])
        && !naziv.equalsIgnoreCase(dozvoljeniNazivi[3])) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "Sastojak: " + naziv +
                " (kolicina: " + kolicina +
                " " + jedinicaMere + ")";
    }
}
