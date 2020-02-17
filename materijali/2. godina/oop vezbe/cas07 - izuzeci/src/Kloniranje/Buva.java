package Kloniranje;

public class Buva extends Zivotinja implements Cloneable {
    private String ime;
    private String podvrsta;

    public Buva(String ime, String podvrsta) {
        super("Buva");
        this.ime = ime;
        this.podvrsta = podvrsta;
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    public String getIme() {
        return ime;
    }

    public String getPodvrsta() {
        return podvrsta;
    }


    @Override
    public void zvuk() {
        System.out.println("Pssst!");
    }

    @Override
    public String toString() {
        return super.toString() + " - " + this.ime + ", " + this.podvrsta;
    }

    public Object clone() throws CloneNotSupportedException{
        return super.clone();
    }
}
