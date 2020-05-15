public class nizovi05 {
    /* Program ilustruje DFS algoritam za obilazak grafa.
     * Graf cuvamo u matrici, a polje (i, j) je definisano kao:
      * a[i][j] = 1 -> cvor i ima granu ka cvoru j
      * a[i][j] = 0 -> cvor i nema granu ka cvoru j*/

    public static void main(String[] args) {
        int[][] graf = {
                {0, 1, 0, 1, 0},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 1, 1},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0}
        };

        boolean[] posecen = {false, false, false, false, false};

        int pocetniCvor = 0;
        dfs(graf, pocetniCvor, posecen);
    }

    static void dfs(int[][] graf, int trenutniCvor, boolean[] posecen){
        posecen[trenutniCvor] = true;
        System.out.println(trenutniCvor);

        for (int i = 0; i < graf.length; i++) {
            if(!posecen[i] && graf[trenutniCvor][i] == 1)
                dfs(graf, i, posecen);
        }
    }
}
