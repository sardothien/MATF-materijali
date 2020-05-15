public class Valjak extends Paket {

    private double a, h;

    public Valjak(double a, double h) {
        this.a = a;
        this.h = h;
    }


    @Override
    public char vrsta() {
        return 'V';
    }

    @Override
    public double zapremina() {
        return a*a*Math.PI*h;
    }

    @Override
    public double povrsina() {
        return 2*a*Math.PI*(a + h);
    }

    @Override
    public String toString() {
        return super.toString() + '(' + a + ", " + h + "), " +
                "V = " + String.format("%.2f", zapremina());
    }
}
