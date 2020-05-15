package dodatnoTokoviPodataka;

import java.util.stream.IntStream;

public class Example03IntRange {

    public static void main(String[] args) {
        // Trazimo kvadrate svih parnih brojeva do n.
        int n = 16;
        IntStream.range(1, 16)
                .filter(x -> x % 2 == 0)
                .map(x -> x*x)
                .forEach(System.out::println);
    }
}
