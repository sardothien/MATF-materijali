package Kalkulator;

public class Izraz {

    private double a, b;
    private Operacija op;

    public Izraz(double a, double b, Operacija op) {
        this.a = a;
        this.b = b;
        this.op = op;
    }

    public double izracunaj(){
        switch (op){
            case DELJENJE:
                if(b != 0)
                    return a/b;
                else{
                    System.err.println("Nije dozvoljeno deljenje nulom.");
                    return 0.0;
                }
            case KOREN: return Math.sqrt(a);
            case MNOZENJE: return a*b;
            case ODUZIMANJE: return a-b;
            case SABIRANJE: return a+b;
            default:
                System.err.println("Nije podrzana operacija " + op.toString());
                return 0.0;
        }
    }

    @Override
    public String toString() {
        if (op == Operacija.KOREN)
            return "√" + a + " = " + izracunaj();
        return a + " " + op + " " + b + " = " + izracunaj();
    }
}
