import java.util.List;

public class RacunarZaCuvanje extends Racunar {

    private int velicinaDiska; // u MB
    private boolean backup;

    public RacunarZaCuvanje(String ime, double cenovniKoef, int velicinaDiska, boolean backup) {
        super(ime, cenovniKoef);
        this.velicinaDiska = velicinaDiska;
        this.backup = backup;
    }

    public int getVelicinaDiska() {
        return velicinaDiska;
    }

    public boolean isBackup() {
        return backup;
    }


    @Override
    public double izracunajCenu(List<Integer> duzineKoriscenja) {
        double cena = 0;
        for (int i : duzineKoriscenja){
            cena += velicinaDiska*0.000001*getCenovniKoef();
            if (backup)
                cena += cena/2;
        }
        return cena;
    }

    @Override
    public String toString() {
        String bu = backup ? "backup" : "nobackup";
        return "[Cuvanje]" + getIme() + " sa " + velicinaDiska +
                "MB diska(" + bu + ") " +
                "koef. cene: " + getCenovniKoef();
    }
}
