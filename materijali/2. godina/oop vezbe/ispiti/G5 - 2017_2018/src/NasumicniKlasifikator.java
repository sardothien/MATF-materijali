import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class NasumicniKlasifikator extends Klasifikator {

    public NasumicniKlasifikator(List<Podatak> podaci) {
        super(podaci);
    }

    @Override
    public List<Pol> klasifikuj() {
        List<Pol> predikcija = new ArrayList<>();
        Random rand = new Random();
        rand.setSeed(42);

        for (int i = 0; i < getPodaci().size(); i++) {
            if (rand.nextDouble() < 0.5)
                predikcija.add(Pol.MUSKI);
            else
                predikcija.add(Pol.ZENSKI);
        }

        return predikcija;
    }

    @Override
    public String toString() {
        return "Nasumicni klasifikator";
    }
}
