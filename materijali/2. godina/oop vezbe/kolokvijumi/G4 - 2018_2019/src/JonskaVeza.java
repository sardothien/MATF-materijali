public class JonskaVeza extends HemijskaVeza {

    public JonskaVeza(Atom atom1, Atom atom2) {
        super(atom1, atom2);
    }

    @Override
    void poveziSe() {

    }

    @Override
    boolean jeMolekul() {
        return false;
    }

    @Override
    public String toString() {
        return "JonskaVeza{}";
    }
}
