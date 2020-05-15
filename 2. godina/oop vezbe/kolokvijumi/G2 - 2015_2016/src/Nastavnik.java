public class Nastavnik extends Zaposleni {

    private static String[] nazivZvanja = {
            "docent", "vanredni", "redovni"
    };

    private String zvanje;

    public Nastavnik(String imeIPrezime, String jmbg, int radnoVreme, String zvanje) {
        super(imeIPrezime, jmbg, radnoVreme);
        this.zvanje = zvanje;
    }

    public Nastavnik(Nastavnik n){
        super(n.getImeIPrezime(), n.getJmbg(), n.radnoVreme);
        zvanje = n.zvanje;
    }

    public static boolean ispravnoZvanje(String zvanje){
        if(!zvanje.equalsIgnoreCase(nazivZvanja[0]) &&
           !zvanje.equalsIgnoreCase(nazivZvanja[1]) &&
           !zvanje.equalsIgnoreCase(nazivZvanja[2])){
            System.out.println("Neispravno zvanje, pokusaj ponovo!");
            return false;
        }
        return true;
    }

    public static int[] dani = {
            31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    public static String jmbgUDatum(String jmbg){
        if (!Nastavnik.jesteJmbg(jmbg))
            return null;

        String dan = jmbg.substring(0, 2);
        String mesec = jmbg.substring(2, 4);
        String godina = "1" + jmbg.substring(4, 7);

        int d = Integer.parseInt(dan);
        int m = Integer.parseInt(mesec);
        int g = Integer.parseInt(godina);

        if(!(g>1900  && (m>=1 && m<=12) && (d>=1 && d<=dani[m-1]))) {
            System.out.println("Pogresan format za jmbg!");
            return null;
        }
        else
            return dan + "." + mesec + "." + godina + ".";
    }

    @Override
    public String toString() {
        return "Nastavnik: " + getImeIPrezime() + '\n' +
                "Datum rodjenja: " + jmbgUDatum(getJmbg()) + '\n' +
                "radni odnos: " + radnoVreme + "%" +'\n' +
                "zvanje: " + zvanje;
    }
}
