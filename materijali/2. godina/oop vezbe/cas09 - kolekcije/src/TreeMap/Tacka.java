package TreeMap;

public class Tacka implements Comparable<Tacka> {

    private int x, y;

    public Tacka(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }


    @Override
    public int compareTo(Tacka o) {
        return this.getX() == o.getX() ? Double.compare(this.getY(), o.getY())
                                       : Double.compare(this.getX(), o.getX());
    }
}
