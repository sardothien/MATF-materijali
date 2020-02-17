package TreeMap;

import java.util.Map;
import java.util.TreeMap;

public class Mapa {

    public static void main(String[] args) {

        Map<String, Integer> bodovi = new TreeMap<>();

        bodovi.put("Marko Markovic", 85);
        bodovi.put("Stefan Stefanovic", 101);
        bodovi.put("Nemanja Nemanjic", 100);
        bodovi.put("Ana Anic", 97);
        bodovi.put("Nina Ninic", 96);
        bodovi.put("Jovana Jovanovic", 80);

        System.out.println("Studenti koji su polagali OOP:");
        for (String kljuc: bodovi.keySet())
            System.out.println("\t- " + kljuc);

        int suma = 0;
        for (Integer bod : bodovi.values())
            suma += bod;

        double prosek = 1.0*suma / bodovi.values().size();
        System.out.println("Prosek poena je " + prosek);

        for (Map.Entry<String, Integer> el : bodovi.entrySet()){
            System.out.print("Student: " + el.getKey());
            System.out.println(", bodovi: " + el.getValue());
        }
    }
}
