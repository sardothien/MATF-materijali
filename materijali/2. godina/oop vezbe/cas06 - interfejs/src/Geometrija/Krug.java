package Geometrija;

public class Krug extends Oblik implements Obim, Povrsina {
    private double r;

    public Krug(Tacka centar, double r) {
        super(centar);
        this.r = r;
    }

    public Krug(){
        super(new Tacka());
        this.r = 10;
    }

    public double getR() {
        return r;
    }

    @Override
    public double getObim() {
        return 2*r*Math.PI;
    }

    @Override
    public double getPovrsina() {
        return r*r*Math.PI;
    }

    @Override
    public String toString() {
        return "Krug";
    }
}
