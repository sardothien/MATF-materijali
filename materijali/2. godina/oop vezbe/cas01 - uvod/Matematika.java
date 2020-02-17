import java.util.Scanner;

public class Matematika {
    static double toRadians(double degs){
        return (degs * Math.PI) / 180;
    }

    static double toDegrees(double radians){
        return (radians * 180) / Math.PI;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite ugao u stepenima: ");
        double fi = sc.nextDouble();
        fi = toRadians(fi);
        // fi = Math.toRadians(fi);

        System.out.println("Uneti ugao u radijanima: " + fi);
        System.out.printf("sin(%g) = %g\n", fi, Math.sin(fi));
        System.out.printf("cos(%g) = %g\n", fi, Math.cos(fi));
        System.out.printf("tan(%g) = %g\n", fi, Math.tan(fi));
        System.out.printf("ctan(%g) = %g\n", fi, 1/Math.tan(fi));

        System.out.println("Unesite realan broj: ");
        double x = sc.nextDouble();
        System.out.printf("sqrt(%g^3) = %g\n", x, Math.sqrt(Math.pow(x, 3)));


        sc.close();
    }
}
