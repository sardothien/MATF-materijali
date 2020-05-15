package primer02;

public class Tacka {

    private double x, y;

    // Podrazumevani konstruktor
    public Tacka(){
        this.x = 0;
        this.y = 0;
    }

    // Standardni konstruktor
    public Tacka(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX(){
        return x;
    }

    public double getY(){
        return y;
    }

    public boolean equals(Tacka t){
        return this.x == t.x && this.y == t.y;
    }

    public void transliraj(double dx, double dy){
        x += dx;
        y += dy;
    }

    public double distance(Tacka t){
        return Math.sqrt((this.x-t.x)*(this.x-t.x) + (this.y-t.y)*(this.y-t.y));
    }

    public String toString(){
        return "(" + x + ", " + y + ")";
    }
}
