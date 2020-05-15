import java.nio.file.Paths;

public abstract class ObjekatIgre implements Comparable<ObjekatIgre>{

    private String naziv;
    protected int x;
    protected int y;

    public ObjekatIgre(String naziv, int x, int y) {
        this.naziv = naziv;
        this.x = x;
        this.y = y;
    }

    public String getNaziv() {
        return naziv;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public abstract void izvrsiAkciju();

    @Override
    public int compareTo(ObjekatIgre o) {
        if (this instanceof Rudnik && o instanceof Tragac)
            return -1;
        else if (this instanceof Tragac && o instanceof Rudnik)
            return 1;
        else if (this instanceof Rudnik && o instanceof Rudnik)
            return Double.compare(((Rudnik) this).getOtvorenJos(), ((Rudnik) o).getOtvorenJos());
        else if (this instanceof Tragac && o instanceof Tragac)
            return -Integer.compare(((Tragac) this).getRanac().getMaxTezina(), ((Tragac) o).getRanac().getMaxTezina());
        else
            return -1;
    }

    @Override
    public String toString() {
        return "[" + x + ", " + y + "] " + naziv;
    }
}
