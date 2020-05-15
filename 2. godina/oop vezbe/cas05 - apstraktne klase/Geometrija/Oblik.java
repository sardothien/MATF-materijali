package Geometrija;

public abstract class Oblik {
    private Tacka centar;

    public Oblik(Tacka centar){
        this.centar = new Tacka(centar);
    }

    public Oblik(){
        centar = new Tacka();
    }

    public Tacka getCentar() {
        return centar;
    }

    public abstract double getObim();
    public abstract double getPovrsina();

    @Override
    public String toString() {
        return "Oblik{" +
                "centar=" + centar +
                '}';
    }
}
