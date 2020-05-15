public class Prava extends PravaPrag{

    public Prava(double a, double b, double c) {
        super(a, b, c);
    }

    public double vrednostKoeficijenta(double A, double B){
        return -A/B;
    }
}
