package Tacka;

public class Main {

    public static void main(String[] args) {
        Tacka t = new Tacka();
        Tacka p = new Tacka(t); // konstruktor kopija
        Tacka s = new Tacka(6, 9);
        Tacka q = s; // referenca na tacku koju povezujemo da pokazuje
                     // na vec postojecu tacku (ne pravimo novi objekat)

        System.out.println("Ukupno instancirano tacaka: " + Tacka.getBrojacTacaka());
        System.out.println("distance(t, s) = " + Tacka.distance(t, s));
        System.out.println("t.distance(s) = " + t.distance(s));

        System.out.println("t = " + t.toString());
        System.out.println("p = " + p.toString());
        System.out.println("s = " + s.toString());
        System.out.println("q = " + q.toString());
    }
}
