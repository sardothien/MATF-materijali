import java.util.Scanner;

public class FibonacijeviBrojevi {
    static int fibonaci(int n){
        if(n == 1 || n == 2)
            return 1;
        else
            return fibonaci(n-1) + fibonaci(n-2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite ceo broj: ");
        int n = sc.nextInt();

        System.out.println("fib(" + n + ") = " + fibonaci(n));

        sc.close();
    }
}
