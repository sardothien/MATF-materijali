package TreeMap;


// Iz datoteke input.txt broji pojavljivanje svih reci

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class BrojanjeReci {

    public static void main(String[] args) {

        Map<String, Integer> ponavljanjeReci = new TreeMap<>();

        Path ulaz = Paths.get("ulaz.txt");
        System.out.println("Ucitavamo datoteku: " + ulaz.toAbsolutePath());

        try {
            List<String> linije = Files.readAllLines(ulaz);

            for (String linija : linije){
                String[] reci = linija.split(" ");
                for (String rec : reci){
                    Integer i = ponavljanjeReci.get(rec);
                    if(i == null)
                        ponavljanjeReci.put(rec, 1);
                    else
                        ponavljanjeReci.put(rec, i+1);
                }
            }

        } catch (IOException e) {
            System.err.println("Neuspesno citanje datoteke: " + ulaz.getFileName());
            e.printStackTrace();
        }

        for (Map.Entry<String, Integer> e : ponavljanjeReci.entrySet())
            System.out.println(e.getKey() + ": " + e.getValue());
    }
}
