import org.omg.PortableInterceptor.INACTIVE;

public class OsobaJMBG extends Osoba {

    private String jmbg;

    public OsobaJMBG(String ime, char pol, String jmbg) {
        super(ime, pol);
        this.jmbg = jmbg;
    }

    @Override
    public String toString() {
        return "OsobaJMBG:\n" +
                "ime i prezime: " + super.getIme() + '\n' +
                "pol: " + super.getPol() + '\n' +
                "JMBG: " + jmbg;
    }

    @Override
    public int brojGodinaOsobe(Datum danasnji_datum) {
        int d = Integer.parseInt(jmbg.substring(0, 2));
        int m = Integer.parseInt(jmbg.substring(2, 4));
        int g = 1000 + Integer.parseInt(jmbg.substring(4, 7));

        int brGodina = danasnji_datum.getGodina() - g;

        if(danasnji_datum.getMesec() < m)
            return brGodina-1;
        else if(danasnji_datum.getMesec() > m)
            return brGodina;
        else if(danasnji_datum.getDan() > d)
            return brGodina;
        else
            return brGodina-1;
    }
}
