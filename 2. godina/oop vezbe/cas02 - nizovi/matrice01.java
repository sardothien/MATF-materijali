import java.util.Arrays;

public class matrice01 {
    public static void main(String[] args) {
        int[][] a = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };

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
