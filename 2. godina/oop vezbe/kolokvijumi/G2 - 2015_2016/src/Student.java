public class Student extends Dosije {
    private int indeks;
    private int godinaUpisa;
    private int profilStudija;
    private static int brojStudenata;

    public Student(String imeIPrezime, String jmbg, int indeks, int godinaUpisa, int profilStudija) {
        super(imeIPrezime, jmbg);
        this.indeks = indeks;
        this.godinaUpisa = godinaUpisa;
        this.profilStudija = profilStudija;
        brojStudenata++;
    }

    public Student(Dosije d, int indeks, int godinaUpisa, int profilStudija) {
        super(d);
        this.indeks = indeks;
        this.godinaUpisa = godinaUpisa;
        this.profilStudija = profilStudija;
    }

    public Student(Student s){
        super(s);
        indeks = s.indeks;
        godinaUpisa = s.godinaUpisa;
        profilStudija = s.profilStudija;
        brojStudenata++;
    }

    public void setProfilStudija(int profilStudija) {
        this.profilStudija = profilStudija;
    }

    public static int getBrojStudenata() {
        return brojStudenata;
    }

    @Override
    public String toString() {
        String studije = "";
        if(profilStudija == 0)
            studije = "Osnovne";
        else if(profilStudija == 1)
            studije = "MSc";
        else
            studije = "PhD";


        String god = Integer.toString(godinaUpisa);

        return "Student: " + getImeIPrezime() + '\n' +
                "jmbg: " + getJmbg() + '\n' +
                "broj indeksa: " + indeks + "/" +
                god.charAt(2) + god.charAt(3) + '\n' +
                "studije: " + studije;
    }
}
