public abstract class HemijskaVeza {

    Atom atom1, atom2;

    public HemijskaVeza(Atom atom1, Atom atom2) {
        this.atom1 = atom1;
        this.atom2 = atom2;
    }

    public static String mogucaVeza(Atom a1, Atom a2){
        if(a1.isNemetal() && a2.isNemetal())
            return "kovalentna veza";
        else if(!a1.isNemetal() && a2.isNemetal())
            return "jonska veza";
        else
            return "veza nije definisana";
    }

    abstract void poveziSe();
    abstract boolean jeMolekul();
}
