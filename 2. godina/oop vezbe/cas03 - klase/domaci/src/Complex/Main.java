package Complex;

public class Main {

    public static void main(String[] args) {
        Complex c1 = new Complex(2, 3);
        Complex c2 = new Complex(2, -4);
        Complex c3 = new Complex(1, 0);
        Complex c4 = new Complex(0, 4);

        Complex[] complexes = {c1, c2, c3, c4};

        for (Complex complex : complexes)
            System.out.println(complex);
    }
}
