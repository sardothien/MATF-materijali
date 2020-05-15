import java.util.Arrays;

public class string06 {
    // Primena metode split()

    public static void main(String[] args) {
        String recenica = "petar petrovic 123/17";
        System.out.println(recenica);

        String[] reci = recenica.split(" ");
        System.out.println(Arrays.toString(reci));

        recenica = "marko, markovic, 101/17, 2i";
        System.out.println(recenica);
        reci = recenica.split(", ");
        System.out.println(Arrays.toString(reci));

        recenica = "oop;programiranje 1;programiranje 2";
        System.out.println(recenica);
        reci = recenica.split(";");
        System.out.println(Arrays.toString(reci));
    }
}