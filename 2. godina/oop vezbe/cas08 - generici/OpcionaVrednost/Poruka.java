package OpcionaVrednost;

import java.util.Random;

public class Poruka {

    private static Random random = new Random();

    public static OpcionaVrednost<String> procitajPoverljivuPoruku(){
        double d = random.nextDouble();
        String sadrzaj;

        if(d < 0.5)
            sadrzaj = "Neki tekst poverljive poruke.";
        else
            sadrzaj = null;

        return OpcionaVrednost.odMozdaNepostojece(sadrzaj);
    }
}