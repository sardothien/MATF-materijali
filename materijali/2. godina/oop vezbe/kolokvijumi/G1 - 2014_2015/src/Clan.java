public class Clan {

    private int a, b;

    public Clan(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public Clan(Clan c){
        this(c.a, c.b);
    }

    public int getA() {
        return a;
    }

    public void setA(int a) {
        this.a = a;
    }

    public int getB() {
        return b;
    }

    public void setB(int b) {
        this.b = b;
    }

    @Override
    public String toString() {
        return "Clan: " +
                "a=" + a +
                ", b=" + b + ".";
    }
}
