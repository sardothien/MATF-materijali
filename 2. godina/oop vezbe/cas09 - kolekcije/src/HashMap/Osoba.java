package HashMap;

public class Osoba {

    private String ime, prezime;

    public Osoba(String ime, String prezime) {
        this.ime = ime;
        this.prezime = prezime;
    }

    @Override
    public String toString() {
        return ime + " " + prezime;
    }

    /* Moramo predefinisati metod equals iz klase Object.
       Ako metod vrati true za dva
       objekta, njihovi hes kodovi moraju biti jednaki.
    */
    @Override
    public boolean equals(Object osoba){
        return prezime.compareTo(((Osoba)osoba).prezime) == 0
            && ime.compareTo(((Osoba)osoba).ime) == 0;
    }

    public int hashCode(){
        return 7*ime.hashCode() + 13*prezime.hashCode();
    }
}
