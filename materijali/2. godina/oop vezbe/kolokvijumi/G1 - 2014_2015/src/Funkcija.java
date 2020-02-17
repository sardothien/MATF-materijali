public abstract class Funkcija {

    private double x;

    public Funkcija(double x) {
        this.x = x;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public abstract double vrednost();
}
