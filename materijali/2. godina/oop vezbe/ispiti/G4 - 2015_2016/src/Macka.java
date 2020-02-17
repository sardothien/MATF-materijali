import java.util.Random;

public class Macka extends Ljubimac {

    private static char karakteri[] = {'x', 'y', 'z', '1', '3', '5', '7', '9'};
    private static int duzina = 3;

    public Macka(String ime, int starost) {
        super(ime, starost);
    }

    public Macka(String ime, int starost, String id) {
        super(ime, starost, id);
    }

    @Override
    public String generisiIdentifikaciju() {
        Random r = new Random();
        StringBuffer sb = new StringBuffer();

        char[] izabrani = new char[duzina];

        for (int i = 0; i < duzina; i++) {
            char izvucen = karakteri[r.nextInt(karakteri.length)];
            for (int j = 0; j < izabrani.length; j++) {
                if (izvucen == izabrani[j]){
                    i--;
                    break;
                }
            }
        }

        for (int i = 0; i < izabrani.length; i++)
            sb.append(karakteri[r.nextInt(karakteri.length)]);

        return sb.toString();
    }

    public static boolean validnaID(String id){
        if (id.length() != duzina)
            return false;

        int j;
        for (int i = 0; i < id.length(); i++)
            for (j = 0; j < id.length(); j++)
                if(id.charAt(i) == id.charAt(j) && i != j)
                    return false;

        for (int i = 0; i < id.length(); i++) {
            for (j = 0; j < karakteri.length; j++) {
                if (id.charAt(i) == karakteri[j])
                    break;
            }
            if (j == karakteri.length)
                return false;
        }

        return true;
    }

    @Override
    public String toString() {
        return "[Macka] " + super.toString();
    }

}
