public class OsobaDatum extends Osoba {

    private Datum datumRodjenja;

    public OsobaDatum(String ime, char pol, Datum datumRodjenja) {
        super(ime, pol);
        this.datumRodjenja = datumRodjenja;
    }

    @Override
    public String toString() {
        return "OsobaDatum:\n" +
                "ime i prezime: " + super.getIme() + '\n' +
                "pol: " + super.getPol() + '\n' +
                "datum rodjenja: " + datumRodjenja.toString();
    }

    @Override
    public int brojGodinaOsobe(Datum danasnji_datum) {
        int brGodina = danasnji_datum.getGodina() - datumRodjenja.getGodina();
        if(danasnji_datum.getMesec() < datumRodjenja.getMesec())
            return brGodina-1;
        else if(danasnji_datum.getMesec() > danasnji_datum.getMesec())
            return brGodina;
        else if(danasnji_datum.getDan() > danasnji_datum.getDan())
            return brGodina;
        else
            return brGodina-1;
    }
}
