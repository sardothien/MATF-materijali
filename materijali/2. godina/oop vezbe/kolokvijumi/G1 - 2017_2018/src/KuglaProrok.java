public class KuglaProrok extends Prorok {

    private String tipKristala;
    private static String[] reciProrocanstvo = {
            "Godine 2020. bice 2020. godina!",
            "Sledece godine iPhone ce biti jos skuplji.",
            "Sutra ce biti vrucina.",
            "Godine 2018. na kolokvijumu iz OOP-a nece biti polimorfizma"
    };

    public KuglaProrok(String ime, int brOstavarenihProrocanstava, int ukupanBrProrocanstava, String tipKristala) {
        super(ime, brOstavarenihProrocanstava, ukupanBrProrocanstava);
        this.tipKristala = (tipKristala != "monociklicni" && tipKristala != "kineski"
                && tipKristala != "tetragonalni") ? "kineski" : tipKristala;
    }

    public KuglaProrok(Prorok p, String tipKristala) {
        super(p);
        this.tipKristala = tipKristala;
    }

    public String getTipKristala() {
        return tipKristala;
    }

    private static int i;
    public String prorekni(){
        String prorocanstvo = reciProrocanstvo[i];
        i = (i+1) % reciProrocanstvo.length;
        return prorocanstvo;
    }

    @Override
    public String toString() {
        return "[kugla prorok]: " + super.toString() + ", tip kristala: " +
                getTipKristala();
    }
}