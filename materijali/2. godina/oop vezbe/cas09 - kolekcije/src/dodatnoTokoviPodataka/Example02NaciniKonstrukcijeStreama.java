package dodatnoTokoviPodataka;

import java.util.Arrays;
import java.util.stream.Stream;

public class Example02NaciniKonstrukcijeStreama {
    public static void main(String[] args) {
        Arrays.asList("a1", "a2", "a3")
                .stream()
                .findFirst()
                .ifPresent(System.out::println);

        // Ne moramo koristiti kolekcije podataka,
        // mozemo jednostavno navesti redom reference
        // objekata od kojih zelimo konstruisati stream.
        Stream.of("a1", "a2", "a3")
                .findFirst()
                .ifPresent(System.out::println);
    }
}
