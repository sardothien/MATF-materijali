public class Supa extends Hrana {

    private double temperatura;

    public Supa(double temperatura) {
        this.temperatura = temperatura;
    }

    public Supa(double temperatura, double tezina, double domet) {
        super(tezina, domet);
        this.temperatura = temperatura;
    }

    public Supa(Supa s){
        this(s.temperatura);
    }

    public double getTemperatura() {
        return temperatura;
    }

    public void setTemperatura(double temperatura) {
        this.temperatura = temperatura;
    }

    @Override
    public void baci() {
        if(temperatura < 30)
            System.out.println("ledena supa krstari vazduhom ka svojoj meti");
        else if(temperatura >= 30 && temperatura <= 45)
            System.out.println("mlaka supa krstari vazduhom ka svojoj meti");
        else
            System.out.println("vrela supa krstari vazduhom ka svojoj meti");
    }

    @Override
    public String toString() {
        return "[Supa] temperatura: " + temperatura + "C, " + super.toString();
    }
}
