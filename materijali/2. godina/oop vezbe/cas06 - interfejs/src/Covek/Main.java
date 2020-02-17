package Covek;

public class Main {

    public static void main(String[] args) {
        Covek c = new Covek("Petar", "Petrovic", 25);
        c.zdravo();
        c.hello();

        // Nesto sto implementira interfejs 'Srpski'
        /* Na ovaj nacin mozemo omoguciti polimorfno izvrsavanje
         * metoda i osloboditi korisnika brige o tome sa kojom
         * klasom radi.*/
        Srpski srp = c;
        srp.dovidjenja();
        srp.hvala();

        Engleski engl = c;
        engl.goodbye();
        engl.hello();

        if(c instanceof Srpski)
            System.out.println("Klasa Covek implementira interfejs Srpski");
        if(c instanceof Engleski)
            System.out.println("Klasa Covek implementira interfejs Engleski");
    }
}
