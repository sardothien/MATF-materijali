public class Jabuka extends  Hrana{

    private String boja;

    public Jabuka(String boja) {
        this.boja = boja;
    }

    public Jabuka( String boja, double tezina, double domet) {
        super(tezina, domet);
        this.boja = boja;
    }

    public Jabuka(Jabuka j){
        this(j.boja);
    }

    public String getBoja() {
        return boja;
    }

    public void setBoja(String boja) {
        this.boja = boja;
    }

    @Override
    public String toString() {
        return "[Jabuka] boja: " + boja + ", " + super.toString();
    }

    @Override
    public void baci() {
        if(getTezina() > 200)
            System.out.println("ogromna " + boja + " jabuka leti kroz vazduh");
        else
            System.out.println(boja + " jabuka leti kroz vazduh");
    }
}
