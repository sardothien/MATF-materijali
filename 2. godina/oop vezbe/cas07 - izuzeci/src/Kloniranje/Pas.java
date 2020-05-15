package Kloniranje;

public class Pas extends Zivotinja implements Cloneable {
    private String ime;
    private String rasa;
    private Buva buva;

    public Pas(String ime, String rasa) {
        super("Pas");
        this.ime = ime;
        this.rasa = rasa;
        this.buva = new Buva("Buvica", "pseca");
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    public String getIme() {
        return this.ime;
    }

    public String getRasa() {
        return this.rasa;
    }

    public Buva getBuva() {
        return this.buva;
    }

    public void setBuva(Buva buva) {
        this.buva = buva;
    }

    @Override
    public void zvuk() {
        System.out.println("aw aw aw");
    }

    @Override
    public String toString() {
        return super.toString() + " - " + this.ime + ", " + this.rasa +
                "\n Sa buvom: " + this.buva;
    }

    public Object clone() throws CloneNotSupportedException{
        return super.clone();
    }
}
