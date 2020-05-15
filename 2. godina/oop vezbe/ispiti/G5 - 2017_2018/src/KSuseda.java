import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KSuseda extends Klasifikator {

    private int brojSuseda;

    public KSuseda(List<Podatak> podaci, int brojSuseda) {
        super(podaci);
        this.brojSuseda = brojSuseda;
    }

    public List<Pol> klasifikuj(){
        List<Pol> labele = new ArrayList<>();

        for (int i = 0; i < getPodaci().size(); i++) {
            List<KSusedaPar> rastojanja = new ArrayList<>();
            for (int j = 0; j < getPodaci().size(); j++) {
                double d = Rastojanje.izracunajRastojanje(getPodaci().get(i), getPodaci().get(j));
                rastojanja.add(new KSusedaPar(j, d));
            }

            Collections.sort(rastojanja);

            for (KSusedaPar par: rastojanja)
                System.out.println(par.getRastojanje());
            System.out.println("-------");

            int brojMuskih = 0, brojZenskih = 0;
            for (int k = 0; k < brojSuseda && k < rastojanja.size(); k++) {
                if (rastojanja.get(k).getIndeksUPodacima() == i)
                    continue;

                if (getPodaci().get(rastojanja.get(k).getIndeksUPodacima()).getPol() == Pol.MUSKI)
                    brojMuskih++;
                else if (getPodaci().get(rastojanja.get(k).getIndeksUPodacima()).getPol() == Pol.ZENSKI)
                    brojZenskih++;
                else
                    System.out.println("PROBLEM! :(");
            }

            if (brojMuskih > brojZenskih)
                labele.add(Pol.MUSKI);
            else
                labele.add(Pol.ZENSKI);
        }

        return labele;
    }

    @Override
    public String toString() {
        return "Klasifikator K najblizih suseda, brojSuseda=" + brojSuseda;
    }
}
