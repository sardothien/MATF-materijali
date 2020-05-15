import java.util.Scanner;

public class TestPrag {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Koeficijenti jednacine prave:");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextInt();

        PravaPrag pp = new PravaPrag(a, b, c);

        System.out.println(pp);

        sc.close();
    }
}
