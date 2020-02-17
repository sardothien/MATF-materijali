import java.util.Scanner;

public class nizovi04 {
    /* Testerasti niz predstavlja niz nizova pri cemu glavni niz
     * sadrzi nizove razlicitih duzina (nije matrica). */

    public static void main(String[] args) {
        int[][] testerastiNiz = {
                {1, 2, 3},
                {4},
                {5, 6}
        };

        ispisi(testerastiNiz);

        System.out.println("Unesite broj nizova:");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] testerica = new int[n][];
        for (int i = 0; i < n; i++) {
            System.out.println("Unesitu duzinu niza br " + i);
            int m = sc.nextInt();
            testerica[i] = new int[m];
            System.out.println("Unesite elemente:");
            for (int j = 0; j < m; j++)
                testerica[i][j] = sc.nextInt();
        }

        ispisi(testerica);
    }

    static void ispisi(int[][] testerastiNiz) {
        for (int[] row: testerastiNiz) {
            for (int e: row)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}
