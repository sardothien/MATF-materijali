import java.util.Scanner;

public class nizovi01 {
    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);

        System.out.println("Unesite duzinu niza:");
        int n = sc.nextInt();

        int[] a = new int[n];

        System.out.println("Unesite " + n + " brojeva:");
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        System.out.println("Uneti brojevi (for petlja):");
        for (int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
        System.out.println();

        System.out.println("Uneti brojevi (foreach petlja):");
        for (int e : a)
            System.out.print(e + " ");
    }
}
