public class IgracPokemon extends Pokemon {

    private int izabranaMagija; // 1 ili 2

    public IgracPokemon(String ime, int nivo, Magija magija1, Magija magija2) {
        super(ime, nivo, magija1, magija2);
        izabranaMagija = 1;
    }

    public Magija getIzabranaMagija() {
        return izabranaMagija == 1 ? getMagija1() : getMagija2();
    }

    public void setIzabranaMagija(int i){
        if (i != 1 && i != 2)
            return;
        izabranaMagija = i;
    }

    @Override
    public void baciMagiju(Pokemon neprijatelj) {
        if (izabranaMagija == 1) {
            neprijatelj.nanesiStetu(getMagija1().getSnaga());
            setPoslednjaBacena(getMagija1());
        }
        else {
            neprijatelj.nanesiStetu(getMagija2().getSnaga());
            setPoslednjaBacena(getMagija2());
        }
    }

    @Override
    public String toString() {
        return "[p] " + super.toString();
    }
}
