import java.util.Arrays;
import java.util.List;

public class Primer01 {

    public static void main(String[] args) {

        List<String> mojaLista = Arrays.asList("a1", "a2", "b1", "c2", "c1");

        mojaLista.stream().filter(s -> s.startsWith("c"))
                          .map(String::toUpperCase)
                          .sorted()
                          .forEach(System.out::println);
    }
}
