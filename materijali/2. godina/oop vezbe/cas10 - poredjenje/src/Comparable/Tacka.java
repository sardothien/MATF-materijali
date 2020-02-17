package Comparable;

public class Tacka implements Comparable<Tacka>{

    private int x, y;

    public Tacka(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Tacka() {
        this(0, 0);
    }

    public Tacka(Tacka t){
        this(t.x, t.y);
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
        if(this.x == o.x)
            return this.y - o.y;
        return this.x - o.x;
    }
}
