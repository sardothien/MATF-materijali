package Kloniranje;

public abstract class Zivotinja implements Cloneable{

    private String vrsta;

    public Zivotinja(String vrsta) {
        this.vrsta = vrsta;
    }

    public Zivotinja(){

    }

    public abstract void zvuk();

    @Override
    public String toString() {
        return "Zivotinja: " + vrsta;
    }
}
