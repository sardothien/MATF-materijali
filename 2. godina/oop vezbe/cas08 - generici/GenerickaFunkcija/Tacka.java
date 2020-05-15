package GenerickaFunkcija;

public class Tacka {

    private int x, y;

    public Tacka(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" + x +
                ", " + y + ")";
    }
}
