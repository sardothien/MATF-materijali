import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Arrays;
import java.util.List;

public class CitanjePisanje {

    // interfejs Path predstavlja apstrakciju putanje na fajl sistemu
    // ne moze se pozvati new Path(...)

    public static void main(String[] args) {

        Path ulaznaPutanja = Paths.get("input.txt");

        System.out.println("path.toString() = " + ulaznaPutanja);

        // Ako je path: /home/korisnik/Desktop/input.txt
        // getFileName(): vratice se "input.txt"
        // getParent(): vratice se "/home/korisnik/Desktop"
        // getRoot(): vratice se "/"

        System.out.println("Ime datoteke: " + ulaznaPutanja.getFileName());
        System.out.println("Parent putanje: " + ulaznaPutanja.getParent());
        System.out.println("Root: " + ulaznaPutanja.getRoot());

        System.out.println("Apsolutna putanja: " + ulaznaPutanja.toAbsolutePath().toString());

        System.out.println("-----------------------------------------------------");

        // citanje
        try {
            List<String> linije = Files.readAllLines(ulaznaPutanja, StandardCharsets.UTF_8);
            System.out.println("Sadrzaj datoteke: " + ulaznaPutanja.toAbsolutePath());
            for(String l : linije)
                System.out.println(l);
        } catch (IOException e) {
            System.out.println("Neuspelo otvaranje ulazne datoteke!");
            e.printStackTrace();
        }

        System.out.println("-----------------------------------------------------");

        // pisanje
        Path izlaznaPutanja = Paths.get("output.txt");
        System.out.println("Pisemo u datoteku: " + izlaznaPutanja.toAbsolutePath());

        List<String> linije;
        linije = Arrays.asList("Zdravo", " ", "svete", "!");

        try {
            Files.write(izlaznaPutanja, linije, StandardOpenOption.APPEND);
            System.out.println("Sadrzaj je uspesno upisan!");
        } catch (IOException e) {
            System.out.println("Neuspelo pisanje u datoteku!");
            e.printStackTrace();
        }
    }
}
