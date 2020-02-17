import java.util.Scanner;

public class TestPrag {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Koordinate vektora:");
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        double z = sc.nextDouble();

        Vektor vektor = new Vektor(x, y, z);

        System.out.println(vektor);

        sc.close();
    }
}
