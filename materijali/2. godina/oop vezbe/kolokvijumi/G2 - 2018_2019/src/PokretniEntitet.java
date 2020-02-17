public class PokretniEntitet extends Entitet {

    private double brzina;
    private double ugao;

    public PokretniEntitet(double brzina, double ugao) {
        this.brzina = brzina;
        this.ugao = ugao;
    }

    public PokretniEntitet(double x, double y, int vitalnost, double brzina, double ugao) {
        super(x, y, vitalnost);
        this.brzina = brzina;
        this.ugao = ugao;
    }

    public double getBrzina() {
        return brzina;
    }

    public void setBrzina(double brzina) {
        this.brzina = brzina;
    }

    public double getUgao() {
        return ugao;
    }

    public void setUgao(double ugao) {
        this.ugao = ugao;
    }

    public void pomeriSe(){
        setX(getX() + brzina*Math.cos(ugao));
        setY(getY() + brzina*Math.sin(ugao));
    }

    @Override
    public String toString() {
        return "PokretniEntitet: " + super.toString() + " | brzina: " +
                brzina + ", ugao: " + ugao;
    }
}
