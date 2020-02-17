public class Zvucnik {
    private String proizvodjac;
    private String model;
    private int snaga;
    private boolean ukljucen;

    public Zvucnik(String proizvodjac, String model, int snaga) {
        this.proizvodjac = proizvodjac;
        this.model = model;
        this.snaga = snaga;
        this.ukljucen = false;
    }

    public Zvucnik(Zvucnik z) {
        this(z.proizvodjac, z.model, z.snaga);
    }

    public String getProizvodjac() {
        return proizvodjac;
    }

    public String getModel() {
        return model;
    }

    public int getSnaga() {
        return snaga;
    }

    public boolean isUkljucen() {
        return ukljucen;
    }

    public void switchOnOff(){
        if(isUkljucen())
            ukljucen = false;
        else
            ukljucen = true;
    }

    @Override
    public String toString() {
        return "Zvucnik " + proizvodjac + " " + model +
                ", snage " + snaga + "W" +
                 " je iskljucen.";
    }
}
