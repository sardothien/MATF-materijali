package instanceOf;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {

        ArrayList<Oblik> oblici = new ArrayList<>(Arrays.asList(
                new Pravougaonik(new Tacka(2, 3), 10, 20),
                new Krug(new Tacka(2, 3), 10),
                new Krug(new Tacka(1, 5), 50),
                new Pravougaonik(new Tacka(0, 5), 10, 60),
                new Pravougaonik(new Tacka(0, 5), 10, 40),
                new Krug(new Tacka(1, 5), 30)
        ));

        Collections.sort(oblici);
        for (Oblik o : oblici)
            System.out.println(o);
    }
}
