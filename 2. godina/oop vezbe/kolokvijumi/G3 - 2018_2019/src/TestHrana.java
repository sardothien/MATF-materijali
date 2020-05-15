public class TestHrana {

    public static void main(String[] args) {
        Jabuka j1 = new Jabuka("crvena", 220, 60);
        Jabuka j2 = new Jabuka("zelena", 115, 50);
        Supa supa = new Supa(20, 200, 5);

        Dete dete = new Dete("Fica");

        // ispis pre dodavanja jela
        System.out.println(dete.toString());

        dete.dodajJelo(supa);
        dete.dodajJelo(j1);
        dete.dodajJelo(j2);

        // ispis nakon dodavanja jela
        System.out.println(dete.toString());
        System.out.println();

        supa.baci();
        j1.baci();
        j2.baci();
    }
}
