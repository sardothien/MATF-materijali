package Comparator.V2;

import java.util.Comparator;

public class Tacka {

    private int x, y;
    public static final Poredi poredi = new Poredi();

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

    private static class Poredi implements Comparator<Tacka>{

        @Override
        public int compare(Tacka o1, Tacka o2) {
            return o1.getX() != o2.getX() ? Integer.compare(o1.getX(), o2.getX())
                                          : Integer.compare(o1.getY(), o2.getY());
        }
    }

}
