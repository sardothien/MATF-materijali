import java.util.List;

public abstract class Racunar implements Comparable<Racunar>{

    private String ime;
    private double cenovniKoef;

    public String getIme() {
        return ime;
    }

    public double getCenovniKoef() {
        return cenovniKoef;
    }

    public Racunar(String ime, double cenovniKoef) {
        this.ime = ime;
        this.cenovniKoef = cenovniKoef;
    }

    public abstract double izracunajCenu(List<Integer> duzineKoriscenja);

    @Override
    public int compareTo(Racunar o) {
        if (this instanceof RacunarZaObradu && o instanceof RacunarZaCuvanje)
            return -1;
        else if (this instanceof RacunarZaCuvanje && o instanceof RacunarZaObradu)
            return 1;
        else if (this instanceof RacunarZaObradu && o instanceof RacunarZaObradu){
            if (((RacunarZaObradu) this).getBrojProcesora() > ((RacunarZaObradu) o).getBrojProcesora())
                return -1;
            else
                return 1;
        }
        else if (this instanceof RacunarZaCuvanje && o instanceof RacunarZaCuvanje){
            if (((RacunarZaCuvanje) this).getVelicinaDiska() > ((RacunarZaCuvanje) o).getVelicinaDiska())
                return -1;
            else
                return 1;
        }
        return 0;
    }
}
