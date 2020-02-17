import java.util.Scanner;

public class ScannerProvera {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x;
        System.out.println("Unesite ceo broj: ");
        if(sc.hasNextInt()){
            x = sc.nextInt();
            System.out.println("Uneli ste: " + x);
        }
        else {
            System.out.println("Niste uneli ceo broj!");
            System.exit(1);
        }

        double y = 0.0;
        System.out.println("Unesite realan broj: ");
        if(sc.hasNextDouble()){
            y = sc.nextDouble();
            System.out.println("Uneli ste: " + y);
        }
        else{
            System.out.println("Niste uneli realan broj!");
        }

        sc.close();
    }
}
