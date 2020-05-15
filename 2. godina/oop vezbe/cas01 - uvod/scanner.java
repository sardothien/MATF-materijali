import java.util.Scanner;

public class scanner {
    public static void main(String[] args) {
        Scanner sc;
        sc = new Scanner(System.in);

        System.out.println("Unesite ceo broj: ");
        int x = sc.nextInt();
        System.out.println("Uneli ste broj: " + x);

        System.out.println("Unesite realan broj: ");
        double y = sc.nextDouble();
        System.out.println("Uneli ste broj: " + y);

        System.out.println("Unesite rec: ");
        String rec = sc.next();
        System.out.println("Uneli ste: " + rec);

        System.out.println("Unesite 1 karakter: ");
        String karakter = sc.next();
        char z = karakter.charAt(0);
        System.out.println("Uneli ste karakter: " + z);

        sc.close();
    }
}
