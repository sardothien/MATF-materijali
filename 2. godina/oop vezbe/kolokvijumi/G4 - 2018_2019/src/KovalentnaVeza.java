public class KovalentnaVeza extends HemijskaVeza {

    private TipVeze tip;
    private boolean polarna;

    public KovalentnaVeza(Atom atom1, Atom atom2, TipVeze tip, boolean polarna) {
        super(atom1, atom2);
        this.tip = tip;
        this.polarna = polarna;
    }

    public TipVeze getTip() {
        return tip;
    }

    public boolean isPolarna() {
        return polarna;
    }

    @Override
    public String toString() {  // TODO
        return "KovalentnaVeza{" +
                "tip=" + tip +
                ", polarna=" + polarna +
                '}';
    }

    @Override
    void poveziSe() {
        if(atom1.getSimbol().equals("H") || atom2.getSimbol().equals("H"))
            tip = TipVeze.JEDNOSTRUKA;
        else if(atom1.getSimbol().equals("O") || atom2.getSimbol().equals("O"))
            tip = TipVeze.DVOSTRUKA;
        else
            tip = TipVeze.TROSTRUKA;

        if(atom1.getSimbol() != atom2.getSimbol())
            polarna = true;
        else
            polarna =  false;
    }

    @Override
    boolean jeMolekul() {
        return atom1.getBrValentnihE() + atom2.getBrValentnihE() == 2 ||
                atom1.getBrValentnihE() + atom2.getBrValentnihE() == 8 ? true : false;
    }
}
