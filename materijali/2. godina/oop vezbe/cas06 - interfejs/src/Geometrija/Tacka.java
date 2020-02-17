package Geometrija;

public class Tacka {
    private double x, y;

    public Tacka(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Tacka() {
        this(0, 0);
    }

    public double getY() {
        return y;
    }

    public double getX() {
        return x;
    }
}
