public class nizovi06 {

    /* Rotacija matrice u mestu. */

    public static void main(String[] args) {
        int[][] blok = {
                {0, 0, 0},
                {0, 1, 0},
                {1, 1, 1}
        };

        System.out.println("Originalni blok:");
        ispisi(blok);

        System.out.println("Rotacija u levo:");
        rotateLeft(blok);
        ispisi(blok);

        System.out.println("Rotacija u desno:");
        rotateRight(blok);
        ispisi(blok);
        rotateRight(blok);
        ispisi(blok);
    }

    static void rotateRight(int[][] blok){
        transponovati(blok);
        for (int i = 0; i < blok.length; i++) {
            int master = 0, blaster = blok[i].length-1;
            while(master < blaster){
                int tmp = blok[i][master];
                blok[i][master] = blok[i][blaster];
                blok[i][blaster] = tmp;
                master++;
                blaster--;
            }
        }
    }

    static void rotateLeft(int[][] blok){
        transponovati(blok);
        for (int i = 0; i < blok.length; i++) {
            int master = 0, blaster = blok[i].length-1;
            while(master < blaster){
                int tmp = blok[master][i];
                blok[master][i] = blok[blaster][i];
                blok[blaster][i] = tmp;
                master++;
                blaster--;
            }
        }
    }

    static void transponovati(int[][] blok){
        for (int i = 0; i < blok.length; i++) {
            for (int j = i+1; j < blok[i].length; j++) {
                int tmp = blok[i][j];
                blok[i][j] = blok[j][i];
                blok[j][i] = tmp;
            }
        }
    }

    private static void ispisi(int[][] blok){
        for (int[] row: blok){
            for (int e: row){
                if(e == 1)
                    System.out.print("█");
                else
                    System.out.print(" ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
