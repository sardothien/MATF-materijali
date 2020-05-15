package dodatnoTokoviPodataka;

import java.util.stream.Stream;

public class Example05 {
    public static void main(String[] args) {
        Stream.of("d2", "a2", "b1", "b3", "c")
                // Sortiramo kolekciju sa nasom funkcijom
                // koja se koristi da algoritmu definise
                // kako da poredi elemente medjusobno.
                .sorted((s1, s2) -> {
                    System.out.printf("sort: %s; %s\n", s1, s2);
                    return s1.compareTo(s2);
                })
                // Svako slovo prebacujemo u veliko.
                .map(s -> {
                    System.out.println("map: " + s);
                    return s.toUpperCase();
                })
                // Zadrzavamo samo one koji pocinju sa slovom 'a'.
                .filter(s -> {
                    System.out.println("filter: " + s);
                    return s.startsWith("a");
                })
                // Ispisujemo rezultate.
                .forEach(s -> System.out.println("forEach: " + s));

        // Da li postoji bolji (brzi, kraci, optimalan) redosled
        // operacija tako da pipeline (niz transformacija) ucini
        // manje posla?

        System.out.println("---------------------------------------");

        Stream.of("d2", "a2", "b1", "a1", "b3", "c")
                .sorted()
                .map(s -> s.toUpperCase())
                .filter(s -> s.startsWith("A"))
                .forEach(System.out::println);
    }
}
