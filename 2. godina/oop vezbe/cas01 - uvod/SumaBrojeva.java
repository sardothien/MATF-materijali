import java.util.Scanner;

public class SumaBrojeva {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int suma = 0;
        int x = sc.nextInt();

        while (x != 0) {
            suma += x;
            x = sc.nextInt();
        }

        sc.close();

        System.out.println("Suma unetih brojeva: " + suma);
    }
}
