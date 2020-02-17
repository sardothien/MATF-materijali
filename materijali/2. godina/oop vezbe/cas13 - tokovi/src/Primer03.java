import java.util.stream.IntStream;

public class Primer03 {

    public static void main(String[] args) {

        int n = 16;

        IntStream.range(1, n)
                .filter(x -> x % 2 == 0)
                .map(x -> x*x)
                .forEach(System.out::println);
    }
}
