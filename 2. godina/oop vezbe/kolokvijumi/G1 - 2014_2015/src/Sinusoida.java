public class Sinusoida extends Funkcija {

    private Clan clan;

    public Sinusoida(double x, Clan clan) {
        super(x);
        this.clan = clan;
    }

    @Override
    public String toString() {
        return "Funkcija:\n" + clan.getA() + "*sin(" + clan.getB() + "*" +
                getX() + "*PI)";
    }

    @Override
    public double vrednost() {
        return clan.getA()*Math.sin(clan.getB()*getX()*Math.PI);
    }
}
