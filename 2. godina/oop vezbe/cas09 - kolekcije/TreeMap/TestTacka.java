package TreeMap;

import java.util.Map;
import java.util.TreeMap;

public class TestTacka {

    public static void main(String[] args) {
        Map<Tacka, String> tacke = new TreeMap<>();

        tacke.put(new Tacka(2, 3), "A");
        tacke.put(new Tacka(0, 5), "B");
        tacke.put(new Tacka(5, 3), "C");
        tacke.put(new Tacka(6, 3), "D");
        tacke.put(new Tacka(6, 2), "E");

        for (Map.Entry<Tacka, String> e : tacke.entrySet())
            System.out.println(e.getKey() + ": " + e.getValue());
    }
}
