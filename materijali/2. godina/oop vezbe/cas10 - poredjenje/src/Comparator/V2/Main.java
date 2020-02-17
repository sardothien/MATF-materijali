package Comparator.V2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        List<Tacka> tacke = new ArrayList<>(Arrays.asList(
                new Tacka(2, 3),
                new Tacka(2, 5),
                new Tacka(3, 1),
                new Tacka(-1, 1),
                new Tacka(7, 6),
                new Tacka(5, -7),
                new Tacka(-3, 2),
                new Tacka(5, -6)
        ));

        Collections.sort(tacke, Tacka.poredi);
        System.out.println(tacke);
    }
}
