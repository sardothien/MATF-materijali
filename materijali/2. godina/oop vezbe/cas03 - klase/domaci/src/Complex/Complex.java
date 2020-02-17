package Complex;

import java.util.concurrent.CompletionException;

public class Complex {
    private double realan;
    private double imaginaran;

    public Complex(double realan, double imaginaran){
        this.realan = realan;
        this.imaginaran = imaginaran;
    }

    public double getReal(){
        return realan;
    }

    public double getImag(){
        return imaginaran;
    }

    public Complex add(Complex t){
        t.realan += realan;
        t.imaginaran += imaginaran;
        return t;
    }

    public Complex substract(Complex t){
        t.realan -= realan;
        t.imaginaran -= imaginaran;
        return t;
    }

    public Complex multiply(Complex t){
        double x1 = t.realan;
        double y1 = t.imaginaran;

        t.realan *= realan;
        x1 *= imaginaran;

        t.imaginaran *= realan;
        y1 *= imaginaran;

        t.realan += y1;
        t.imaginaran += x1;

        return t;
    }

    /* TODO:
        public Complex divide(Complex t){}
    */

    public String toString(){
        return realan + " + " + imaginaran + "i";
    }
}
