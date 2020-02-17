package HashMap;

import java.util.HashMap;
import java.util.Map;

public class TelefonskiImenik {

    /* Neophodno je da za kljuceve budu predefinisani metodi equals
	   i hashCode iz klase Object. Hes kod odredjuje mesto u
	   tabeli gde ce element biti smesten.

	   Za implementaciju ovih metoda mora biti ispunjen uslov da
	   ako metod equals vrati true za dva objekta onda metod
	   hashCode mora vratiti istu vrednost za oba.
	*/

    public static void main(String[] args) {

        HashMap<Osoba, String> imenik = new HashMap<>();

        imenik.put(new Osoba("Ana", "Anic"), "0611234567");
        imenik.put(new Osoba("Jovana", "Jovanovic"), "0659876543");
        imenik.put(new Osoba("Bojana", "Bojanic"), "062345678");
        imenik.put(new Osoba("Pavle", "Pavlovic"), "0645678901");

        // menja se vrednost
        imenik.put(new Osoba("Ana", "Anic"), "0612233445");

        for (Map.Entry<Osoba, String> unos: imenik.entrySet())
            System.out.println(unos.getKey() + ": " + unos.getValue());
    }
}
