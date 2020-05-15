public class Entitet implements Blokira {

    private double x, y;
    private int vitalnost;
    private boolean blokira;

    public Entitet() {
        this.x = 0;
        this.y = 0;
        this.vitalnost = 0;
        this.blokira = true;
    }

    public Entitet(double x, double y, int vitalnost) {
        this.x = x;
        this.y = y;
        this.vitalnost = vitalnost > 0 ? vitalnost : 0;
        blokira = true;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public int getVitalnost() {
        return vitalnost;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    @Override
    public boolean isBlokira() {
        return blokira;
    }

    @Override
    public void setBlokira(boolean blok) {
        this.blokira = blok;
    }

    @Override
    public String toString() {
        String znak = blokira == true ? "+" : "-";
        return "(" + x + ", " + y  + ") [" + vitalnost + " HP] " + znak;
    }
}
