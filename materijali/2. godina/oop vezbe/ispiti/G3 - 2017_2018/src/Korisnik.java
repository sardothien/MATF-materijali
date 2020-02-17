import java.util.Map;
import java.util.TreeMap;

public class Korisnik {

    private String nadimak;
    private Map<ZabavniSadrzaj, Integer> ocenjenSadrzaj;

    public Korisnik(String nadimak) {
        this.nadimak = nadimak;
        ocenjenSadrzaj = new TreeMap<>();
    }

    public String getNadimak() {
        return nadimak;
    }

    public Map<ZabavniSadrzaj, Integer> getOcenjenSadrzaj() {
        return ocenjenSadrzaj;
    }

    public void oceniSadrzaj(ZabavniSadrzaj zp, int ocena){
        ocenjenSadrzaj.put(zp, ocena);
    }
}
