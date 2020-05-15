import java.util.Random;

public class CpuPokemon extends Pokemon {

    private static Random random = new Random();

    public CpuPokemon(String ime, int nivo, Magija magija1, Magija magija2) {
        super(ime, nivo, magija1, magija2);
    }

    @Override
    public void baciMagiju(Pokemon neprijatelj) {
        if (random.nextDouble() <= 0.5){
            neprijatelj.nanesiStetu(getMagija1().getSnaga());
            setPoslednjaBacena(getMagija1());
        }
        else{
            neprijatelj.nanesiStetu(getMagija2().getSnaga());
            setPoslednjaBacena(getMagija2());
        }
    }

    @Override
    public String toString() {
        return "[ai] " + super.toString();
    }
}
