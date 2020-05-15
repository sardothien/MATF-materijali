public class TestAtom {

    public static void main(String[] args) {
        Atom vodonik = new Atom();
        Atom kiseonik = new Atom(8, "O", 6, true);
        Atom azot = new Atom(7, "N", 6, true);

        Atom[] atomi = {vodonik, kiseonik, azot};
        for (Atom a : atomi)
            System.out.println(a);
    }
}
