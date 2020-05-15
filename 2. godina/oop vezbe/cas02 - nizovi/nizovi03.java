import java.util.Scanner;

public class nizovi03 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int[] a = unesi();

        System.out.println("Unesite konstantu:");
        int c = sc.nextInt();

        System.out.println("Uneti niz:");
        ispisi(a);

        pomnoziKonstantom(a, c);

        System.out.println("Promenjen niz:");
        ispisi(a);
    }

    static void pomnoziKonstantom(int[] a, int c){
        for (int i = 0; i < a.length; i++) {
            a[i] *= c;
        }
    }

    static void ispisi(int[] a){
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    static int[] unesi(){
        sc = new Scanner(System.in);

        System.out.println("Unesite velicinu niza:");
        int n = sc.nextInt();

        System.out.println("Unesite elemente niza:");
        int[] tmp = new int[n];
        for (int i = 0; i < n; i++)
            tmp[i] = sc.nextInt();
        return tmp;
    }
}
