import java.util.Arrays;

public class Recept {
    private Sastojak[] sastojci;

    public Recept(Sastojak[] sastojci) {
        this.sastojci = new Sastojak[sastojci.length];
        for (int i = 0; i < sastojci.length; i++)
            this.sastojci[i] = new Sastojak(sastojci[i]);
    }

    public Sastojak[] getSastojci() {
        return sastojci;
    }

    @Override
    public String toString() {
        String pom = "Lista sastojaka:\n";
        for (int i = 0; i < sastojci.length; i++) {
            pom += ((i+1) + ". " + sastojci[i] + '\n');
        }
        return pom;
    }
}
