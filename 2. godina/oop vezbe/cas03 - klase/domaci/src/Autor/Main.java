package Autor;

public class Main {

    public static void main(String[] args) {
        Autor a1 = new Autor("Milan", "Milanovic", 1958);
        Autor a2 = new Autor("Ana", "Sljivic", 1986);
        Autor a3 = new Autor("Marija", "Tomic", 1934);
        Autor a4 = new Autor("Igor", "Micic", 1928);
        Autor a5 = new Autor("Uros", "Todorovic", 1990);

        Autor[] autori = {a1, a2, a3, a4, a5};

        for(Autor a : autori) {
            System.out.println(a);
            System.out.println("-----------------------------------------");
        }

        // System.out.println(a1.getGodine());
    }
}
