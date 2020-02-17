import java.util.List;

public abstract class Klasifikator {

    private List<Podatak> podaci;

    public Klasifikator(List<Podatak> podaci) {
        this.podaci = podaci;
    }

    public List<Podatak> getPodaci() {
        return podaci;
    }

    public double greska(List<Pol> labele){
        int brPogodjenih = 0;

        for (int i = 0; i < podaci.size(); i++)
            if (podaci.get(i).getPol() == labele.get(i))
                brPogodjenih++;

        return brPogodjenih*1.0 / podaci.size();
    }

    public abstract List<Pol> klasifikuj();
}
