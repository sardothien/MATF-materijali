public class TestFilm {

    public static void main(String[] args) {
        String[] zanr1 = {"adventure", "comedy", "sci-fi"};
        Film f1 = new Film("Povratak u buducnost", zanr1, 8.5);
        String[] zanr2 = {"adventure", "family", "fantasy"};
        Film f2 = new Film("Hari Poter i zatvorenik iz Askabana", zanr2, 8.0);
        String[] zanr3 = {"drama", "romance"};
        Film f3 = new Film("Titanik", zanr3, 7.8);
        String[] zanr4 = {"adventure", "drama", "fantasy"};
        Film f4 = new Film("Gospodar prstenova: Dve kule", zanr4, 9.3);

        Film[] filmovi = {f1, f2, f3, f4};
        for (Film film: filmovi) {
            System.out.println(film);
            System.out.println("--------------------------------");
        }
    }
}
