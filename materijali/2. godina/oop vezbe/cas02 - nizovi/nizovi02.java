import java.util.Scanner;

public class nizovi02 {
    public static void main(String[] args) {
        int[] a = unesi();
        ispisi1(a);
        ispisi2(a);
    }

    static void ispisi1(int[] a){
        for(int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    static void ispisi2(int[] a){
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    static int[] unesi(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite velicinu niza:");
        int n = sc.nextInt();

        System.out.println("Unesite elemente niza:");
        int[] tmp = new int[n];
        for (int i = 0; i < n; i++)
            tmp[i] = sc.nextInt();
        return tmp;
    }
}
