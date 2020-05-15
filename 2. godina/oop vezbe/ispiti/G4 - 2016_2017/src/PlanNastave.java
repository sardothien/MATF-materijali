import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PlanNastave {

    public List<Predmet> predmeti;

    public PlanNastave() {
        predmeti = new ArrayList<>();
    }

    public boolean ucitajPredmete(String putanja){
        try {
            List<String> linije = Files.readAllLines(Paths.get(putanja));

            if (linije.isEmpty()) {
                System.out.println("Nema linija u datoteci.");
                return false;
            }

            for (String l : linije){
                String[] tokeni = l.split(",");
                char znak = tokeni[0].charAt(0);
                int godina = Integer.parseInt(tokeni[1]);
                String sifra = tokeni[2].trim();
                String naziv = tokeni[3].trim();

                if (znak == 'O') {
                    int semestar = Integer.parseInt(tokeni[4].trim());
                    int poeni = Integer.parseInt(tokeni[5].trim());
                    predmeti.add(new ObavezanPredmet(sifra, naziv, godina, semestar, poeni));
                }
                else if (znak == 'I') {
                    int poeni = Integer.parseInt(tokeni[4].trim());
                    char blok = tokeni[5].charAt(0);
                    predmeti.add(new IzborniPredmet(sifra, naziv, godina, poeni, blok));
                }
            }

            return true;
        } catch (IOException e) {
            System.out.println("Neuspesno citanje datoteke.");
            return false;
        }
    }

    public boolean ucitajUslovne(String putanja){

        try {
            List<String> linije = Files.readAllLines(Paths.get(putanja));

            if (linije.isEmpty()) {
                System.out.println("Nema linija u datoteci.");
                return false;
            }

            for (String l : linije){
                String[] tokeni = l.split(",");
                dodajUslovni(tokeni[0], tokeni[1]);
            }

            return true;
        } catch (IOException e) {
            System.out.println("Neuspesno citanje datoteke.");
            return false;
        }

    }

    private void dodajUslovni(String predmet, String uslovniPredmet) {
        for (Predmet p : predmeti){
            if (p.getSifra().equals(predmet))
                ((ObavezanPredmet)p).dodajUslovniPredmet(uslovniPredmet);
        }
    }

    public String ispisi(String opseg){ // SVI, OBAVEZNI, IZBORNI

        StringBuilder sb = new StringBuilder();
        Collections.sort(predmeti);

        for (Predmet p : predmeti){
            if (opseg.equals("SVI")){
                sb.append(p.toString() + "\n");
                sb.append("-----------------------------------\n");
            }
            else if(opseg.equals("OBAVEZNI")){
                if (p instanceof ObavezanPredmet){
                    sb.append(p.toString() + "\n");
                    sb.append("-----------------------------------\n");
                }
            }
            else if (opseg.equals("IZBORNI")){
                if (p instanceof IzborniPredmet){
                    sb.append(p.toString() + "\n");
                    sb.append("-----------------------------------\n");
                }
            }
        }

        return sb.toString();
    }
}
