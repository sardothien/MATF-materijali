package Knjiga;

import Autor.Autor;

public class Main {

    public static void main(String[] args) {
        Autor a1 = new Autor("Robert", "Dzordan", 1948);
        Autor a2 = new Autor("Daniel", "Suarez", 1964);

        Knjiga k1 = new Knjiga("Zenica sveta", a1, 9.7);
        Knjiga k2 = new Knjiga("Demon", a2, 9.5);
        Knjiga k3 = new Knjiga("Sloboda", a2, 9.1);

        Knjiga[] knjige = {k1, k2, k3};

        for(Knjiga k: knjige) {
            System.out.println(k);
            System.out.println("-----------------------------------------");
        }
    }
}
