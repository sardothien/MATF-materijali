package primer01;

public class Student {

    private String ime, prezime, indeks;
    private double prosek;

    // Konstruktor - fja koja se poziva pri pravljenju objekta
    public Student(String ime, String prezime, String indeks, double prosek){
        this.ime = ime;
        this.prezime = prezime;
        this.indeks = indeks;
        this.prosek = prosek;
    }

    // Geteri - fje koje vracaju nase klase kao deo ternutnog stanja objekta
    public String getIme(){
        return ime;
    }
    public String getPrezime(){
        return prezime;
    }
    public String getIndeks(){
        return indeks;
    }
    public int getGodinaUpisa(){
        String tmp = "20" + indeks.charAt(2) + indeks.charAt(3);
        return Integer.parseInt(tmp);
    }
    public int getBrojIndeksa(){
        String tmp = "" + indeks.charAt(4) + indeks.charAt(5) + indeks.charAt(6);
        return Integer.parseInt(tmp);
    }

    // Seter
    public void setIndeks(String indeks){
        if(validirajIndeks(indeks))
            this.indeks = indeks;
        else
            System.out.println("Dati indeks nije u korektnom obliku.");
    }

    private boolean validirajIndeks(String indeks) {
        indeks = indeks.toLowerCase();

        if(indeks.charAt(0) != 'm' && indeks.charAt(0) != 'a')
            return false;

        String smerovi = "mnvlrif";
        if(!smerovi.contains("" + indeks.charAt(1)))
            return false;

        for (int i = 2; i < indeks.length(); i++)
            if(!Character.isDigit(indeks.charAt(i)))
                return false;

        return true;
    }

    private String validirajSmer(char studije, char smer){
        if(studije == 'm'){
            switch (smer) {
                case 'm': return "teorijska matematija";
                case 'n': return "primenjena matematika";
                case 'v': return "statistika";
                case 'l': return "profesor matematike";
                case 'r': return "racunarstvo i matematika";
                case 'i': return "informatika";
                default: return null;
            }
        }
        else if(studije == 'a' && smer == 'f')
            return "astrofizika";
        else if(studije == 'a' && smer == 'i')
            return "astroinformatika";
        else
            return null;
    }

    public String getSmer(){
        char studije = indeks.charAt(0);
        char smer = indeks.charAt(1);
        String rez = validirajSmer(studije, smer);
        if(rez == null)
            return "smer nije validan";
        else
            return rez;
    }

    public double getProsek(){
        return prosek;
    }

    public String toString(){
        return ime + " " + prezime + ", " + indeks + ", " + prosek;
    }

}