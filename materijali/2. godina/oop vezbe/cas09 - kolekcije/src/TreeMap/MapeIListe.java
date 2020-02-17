package TreeMap;

import java.util.*;

public class MapeIListe {

    public static void main(String[] args) {

        Map<String, List<Integer>> bodovi = new TreeMap<>();

        bodovi.put("Marko Markovic", new ArrayList<>(Arrays.asList(6, 7, 8, 9)));
        bodovi.put("Stefan Stefanovic", new ArrayList<>(Arrays.asList(10, 10, 10, 10)));
        bodovi.put("Nemanja Nemanjic", new ArrayList<>(Arrays.asList(9, 10, 10, 10)));
        bodovi.put("Ana Anic", new ArrayList<>(Arrays.asList(9, 10, 10, 10)));
        bodovi.put("Nina Ninic", new ArrayList<>(Arrays.asList(6, 8, 8, 10)));
        bodovi.put("Mirjana Miric", new ArrayList<>(Arrays.asList(8, 8, 8, 10)));

        Map<String, Float> proseci = new TreeMap<>();
        for (Map.Entry<String, List<Integer>> e : bodovi.entrySet()){
            String ime = e.getKey();
            float prosek = 0;

            for (Integer ocena : e.getValue())
                prosek += ocena;

            prosek /= e.getValue().size();
            proseci.put(ime, prosek);
        }

        for (Map.Entry<String, Float> prosek : proseci.entrySet())
            System.out.println(prosek.getKey() + ": " + prosek.getValue());
    }
}
