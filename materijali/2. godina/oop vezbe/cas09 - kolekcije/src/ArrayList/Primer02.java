package ArrayList;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Primer02 {

    public static void main(String[] args) {

        // asList vraca ArrayList objekat
        List<Integer> xs = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        System.out.println(xs);
        System.out.println("--------------------------------------------");

        // mesanje elemenata
        Collections.shuffle(xs);
        System.out.println("Nakon mesanja elemenata:");
        System.out.println(xs);
        System.out.println("--------------------------------------------");

        // razmena elemenata
        int i = 0, j = 4;
        Collections.swap(xs, i, j);
        System.out.println("Nakon razmene elemenata:");
        System.out.println(xs);
        System.out.println("--------------------------------------------");

        // min i max
        Integer max = Collections.max(xs);
        Integer min = Collections.min(xs);
        System.out.println("max = " + max);
        System.out.println("min = " + min);
        System.out.println("--------------------------------------------");

        // rotiranje elemenata za k
        int k = 3;
        System.out.println("Nakon rotacije za " + k + " mesta udesno:");
        Collections.rotate(xs, k);
        System.out.println(xs);
        System.out.println("Nakon rotacije za " + k + " mesta ulevo:");
        Collections.rotate(xs, -k);
        System.out.println(xs);
        System.out.println("--------------------------------------------");
    }
}
