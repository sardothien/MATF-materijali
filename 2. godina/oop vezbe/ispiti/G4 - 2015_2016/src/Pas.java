import java.util.Random;

public class Pas extends Ljubimac {

    private static char karakteri[] = {'a', 'b', 'c', '2', '4', '6', '8', '0'};
    private static int duzina = 5;

    public Pas(String ime, int starost) {
        super(ime, starost);
    }

    public Pas(String ime, int starost, String id) {
        super(ime, starost, id);
    }

    @Override
    public String generisiIdentifikaciju() {
        Random r = new Random();
        StringBuffer sb = new StringBuffer();

        for (int i = 0; i < duzina; i++)
            sb.append(karakteri[r.nextInt(karakteri.length)]);

        int indeks = r.nextInt(duzina);
        sb.replace(indeks, indeks+1, karakteri[3+r.nextInt(5)] + "");

        return sb.toString();
    }

    public static boolean validnaID(String id){
        if (id.length() != duzina)
            return false;

        int j;
        for (int i = 0; i < id.length(); i++) {
            for (j = 0; j < karakteri.length; j++) {
                if (id.charAt(i) == karakteri[j])
                    break;
            }
            if (j == karakteri.length)
                return false;
        }

        int br = 0;
        for (j = 0; j < id.length(); j++)
            if (Character.isDigit(id.charAt(j)))
                br++;

        if (br == 0)
            return false;

        return true;
    }

    @Override
    public String toString() {
        return "[Pas] " + super.toString();
    }
}
