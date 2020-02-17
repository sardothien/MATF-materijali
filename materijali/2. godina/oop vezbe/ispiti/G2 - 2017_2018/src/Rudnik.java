public class Rudnik extends ObjekatIgre {

    private int otvorenJos;
    private double tezinaDragulja;

    public Rudnik(String naziv, int x, int y, int otvorenJos, double tezinaDragulja) {
        super(naziv, x, y);
        this.otvorenJos = otvorenJos;
        this.tezinaDragulja = tezinaDragulja;
    }

    public int getOtvorenJos() {
        return otvorenJos;
    }

    public double getTezinaDragulja() {
        return tezinaDragulja;
    }

    public boolean isOtvoren(){
        return otvorenJos > 0;
    }

    @Override
    public void izvrsiAkciju() {
        if (isOtvoren())
            otvorenJos--;
    }

    @Override
    public String toString() {
        return "Rudnik: " + super.toString() + " je otvoren jos " +
                otvorenJos + " poteza.";
    }
}
