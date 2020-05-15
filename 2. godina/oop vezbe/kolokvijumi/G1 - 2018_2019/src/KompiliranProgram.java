public class KompiliranProgram extends Program {

    private int brojInstrukcija;

    public KompiliranProgram(String ime, double potrebnoMemorije, Platforma platforma, int brojInstrukcija) {
        super(ime, potrebnoMemorije, platforma);
        this.brojInstrukcija = brojInstrukcija;
    }

    public KompiliranProgram(Program p, int brojInstrukcija) {
        super(p);
        this.brojInstrukcija = brojInstrukcija;
    }


}
