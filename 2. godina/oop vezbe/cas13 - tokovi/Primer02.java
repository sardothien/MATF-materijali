import java.util.Arrays;
import java.util.stream.Stream;

public class Primer02 {

    public static void main(String[] args) {

        Arrays.asList("a1", "a2", "a3").stream()
                .findFirst()
                .ifPresent(System.out::println);

        Stream.of("a1", "a2", "a3").findFirst().ifPresent(System.out::println);
    }
}
