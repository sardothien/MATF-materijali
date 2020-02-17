import java.util.Arrays;
import java.util.Scanner;

public class matrice02 {
    public static void main(String[] args) {
        int[][] a = unesi();

        System.out.println("ispisi1(a):");
        ispisi1(a);
        System.out.println();

        System.out.println("ispisi2(a):");
        ispisi2(a);
        System.out.println();

        System.out.println("ispisi3(a):");
        ispisi3(a);
        System.out.println();
    }

    private static int[][] unesi(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesi dimenzije matrice:");
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] tmp = new int[n][m];

        System.out.println("Unesite matricu datih dimenzija:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp[i][j] = sc.nextInt();

        return tmp;
    }

    static void ispisi1(int[][] a){
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++)
                System.out.printf("%d ", a[i][j]);
            System.out.println();
        }
    }

    static void ispisi2(int[][] a){
        for (int[] tmp : a) {
            for (int e : tmp)
                System.out.print(e + " ");
            System.out.println();
        }
    }

    static void ispisi3(int[][] a){
        System.out.println(Arrays.deepToString(a));
    }
}
