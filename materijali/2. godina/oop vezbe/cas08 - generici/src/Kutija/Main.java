package Kutija;

public class Main {

    public static void main(String[] args) {
        Kutija<Integer> kutija = new Kutija<Integer>();

        System.out.println("Ubacuje se predmet 10.");
        kutija.ubaciPredmet(10);
        System.out.println(kutija);

        System.out.println("Uklanja se predmet.");
        kutija.uzmiPredmet();
        System.out.println(kutija);
    }
}
