import java.util.Arrays;

public class ZbirSinusoida extends Funkcija {

    private Clan[] clanovi;

    public ZbirSinusoida(double x, Clan[] clanovi) {
        super(x);
        this.clanovi = clanovi;
    }

    @Override
    public String toString() {
        String ispis = "Funkcija: ";
        for (int i = 0; i < clanovi.length; i++) {
            ispis += "+" + clanovi[i].getA() + "*sin(" + clanovi[i].getB() + "*" +
                    getX() + "*PI)";
        }

        return ispis;
    }

    @Override
    public double vrednost() {
        double rez = 0;
        for (int i = 0; i < clanovi.length; i++) {
            rez += clanovi[i].getA()*Math.sin(clanovi[i].getB()*getX()*Math.PI);
        }

        return rez;
    }
}
