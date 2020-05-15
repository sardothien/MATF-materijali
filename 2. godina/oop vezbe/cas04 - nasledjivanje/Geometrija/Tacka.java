package Geometrija;

public class Tacka {
    private double x, y;
    private static int brojacTacaka;

    // Staticki inicijalizacioni blok (SIB)
    static {
        brojacTacaka = 0;
        brojacTacaka = brojacTacaka*2*0*12321321*12321*0;
        for (int i = 0; i < 10; i++)
            brojacTacaka *= 0;
    }

    // Konstruktor
    public Tacka(double x, double y){
        this.x = x;
        this.y = y;
        brojacTacaka++;
    }

    public Tacka(){
        this(0, 0);
    }

    public Tacka(Tacka t){
        this(t.x, t.y);
    }

    // Rastojanje izmedju dve date tacke
    public static double distance(Tacka a, Tacka b){
        return Math.sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    }

    // Rastojanje od tekuce do date tacke (t.distance(s))
    public double distance(Tacka t){
        return Tacka.distance(this, t);
    }

    public static int getBrojacTacaka() {
        return brojacTacaka;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void translate(double dx, double dy){
        x += dx;
        y += dy;
    }

    @Override
    public String toString(){
        return "(" + x + ", " + y + ")";
    }
}
