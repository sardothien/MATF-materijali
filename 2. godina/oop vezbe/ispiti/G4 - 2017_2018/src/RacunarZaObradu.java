import java.util.List;

public class RacunarZaObradu extends Racunar {

    private int brojProcesora;

    public RacunarZaObradu(String ime, double cenovniKoef, int brojProcesora) {
        super(ime, cenovniKoef);
        this.brojProcesora = brojProcesora;
    }

    public int getBrojProcesora() {
        return brojProcesora;
    }

    @Override
    public double izracunajCenu(List<Integer> duzineKoriscenja) {
        double cena = 0;
        for (int i : duzineKoriscenja){
            cena += brojProcesora*Math.sqrt(i)*getCenovniKoef();
            if (i > 1800)
                cena += (1800-i)*brojProcesora*0.2;
        }
        return cena;
    }

    @Override
    public String toString() {
        return "[Obrada]" + getIme() + " sa " + brojProcesora +
                " procesora, koef. cene: " + getCenovniKoef();
    }
}
