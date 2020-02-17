import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class SoftverskaMreza {

    private String ime;
    private Map<String, List<Softver>> podaci;

    public SoftverskaMreza(String ime) {
        this.ime = ime;
        podaci = new TreeMap<>();
    }

    public boolean ucitajPodatke(String putanja){
        try {
            List<String> linije = Files.readAllLines(Paths.get(putanja));

            for (String l : linije){
                String[] tokeni = l.split(", ");
                String tip = tokeni[0].trim();
                String ime = tokeni[1].trim();
                int brojLinija = Integer.parseInt(tokeni[2].trim());
                String jezik = tokeni[3].trim();

                if (!podaci.containsKey(jezik))
                    podaci.put(jezik, new ArrayList<>());

                if (tip.equals("1")){
                    String najcesciJezik = tokeni[4].trim();
                    podaci.get(jezik).add(new Editor(ime, brojLinija, jezik, najcesciJezik));
                }
                else{
                    String opis = tokeni[4].trim();
                    podaci.get(jezik).add(new Biblioteka(ime, brojLinija, jezik, opis));
                }
            }
            return true;
        } catch (IOException e) {
            System.out.println("Neuspesno ucitavanje datoteke.");
            return false;
        }
    }

    public String najpopularnijiJezik(){
        String jezik = "nema podataka";
        int brojPrograma = -1;

        for (Map.Entry<String, List<Softver>> e : podaci.entrySet()){
            if (e.getValue().size() > brojPrograma){
                jezik = e.getKey();
                brojPrograma = e.getValue().size();
            }
        }

        return jezik;
    }

    public List<Softver> softverZaJezik(String jezik){
        return podaci.get(jezik);
    }

    public int ukupnoLInijaKodaZaJezik(String jezik){
        List<Softver> softveri = podaci.get(jezik);

        if (softveri == null)
            return 0;

        int ukuponoLinija = 0;
        for (Softver s : softveri)
            ukuponoLinija += s.getBrojLinija();

        return ukuponoLinija;
    }

    public int ukupnoLinijaKoda(){
        int ukupnoLinija = 0;
        for (String j : podaci.keySet())
            ukupnoLinija += ukupnoLInijaKodaZaJezik(j);

        return ukupnoLinija;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Softverska mreza: " + ime + "\n\n");

        for (Map.Entry<String, List<Softver>> entry : podaci.entrySet()) {
            sb.append(entry.getKey()).append(":\n");
            for (Softver s : entry.getValue())
                sb.append("* " + s.toString() + "\n");
            sb.append("\n");
        }

        return sb.toString();
    }
}
