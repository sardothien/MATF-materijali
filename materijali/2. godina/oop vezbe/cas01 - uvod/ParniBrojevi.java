import java.util.Scanner;

public class ParniBrojevi {

    static void prikaziparne(int n){
        for(int i = 2; i <= n; i += 2)
            System.out.print(i + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        prikaziparne(n);

        sc.close();
    }
}
