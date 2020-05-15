import java.util.Scanner;

public class matrice03 {

    static Scanner sc = new Scanner(System.in);

    // Unos matrice i obrtanje vrste i kolone
    public static void main(String[] args) {
        int[][] a = unesi();

        System.out.println("Unesite indekse vrsti koje razmenjujete:");
        int i = unesiSiguranInt();
        int j = unesiSiguranInt();

        if(i < 0 || j < 0 || i >= a.length || j >= a.length){
            System.out.println("Indeks vrsta mora biti izmedju 0 i " + (a.length-1));
            System.exit(1);
        }

        System.out.println("Pre razmene vrsta " + i + " i " +j);
        ispisi(a);
        System.out.println();

        System.out.println("Posle razmene:");
        razmeniEfikasno(a, i, j);
        ispisi(a);
    }

    // Slozenost O(1)
    static void razmeniEfikasno(int[][] a, int i, int j){
        int[] tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    static void ispisi(int[][] a) {
        for (int[] row: a) {
            for (int e: row)
                System.out.print(e + " ");
            System.out.println();
        }
    }

    private static int[][] unesi(){
        System.out.println("Unesi dimenzije matrice:");
        int n = unesiSiguranInt();
        int m = unesiSiguranInt();

        int[][] tmp = new int[n][m];

        System.out.println("Unesite matricu datih dimenzija:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp[i][j] = unesiSiguranInt();

        return tmp;
    }

    public static int unesiSiguranInt(){
        if(sc.hasNext())
            return sc.nextInt();
        else{
            System.out.println("Niste uneli ceo broj!");
            System.exit(1);
            return 1;
        }
    }
}
