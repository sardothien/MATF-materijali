import java.util.Scanner;

public class zadatak03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        if(n < 0) {
            System.out.println("greska");
            System.exit(1);
        }

        crtaj(n);

        sc.close();
    }

    static void crtaj(int n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i > 0 && i < n-1 && j > 0 && j < n-1)
                    System.out.print(" ");
                else
                    System.out.print("+");
            }
            System.out.println();
        }
    }
}
