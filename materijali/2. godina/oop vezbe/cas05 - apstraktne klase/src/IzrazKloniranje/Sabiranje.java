package IzrazKloniranje;

public class Sabiranje extends BinarnaOperacija {


    public Sabiranje(Izraz levi, Izraz desni) {
        super(levi, desni);
    }

    public Sabiranje(Sabiranje s) {
        super(s.getLevi(), s.getDesni());
    }

    @Override
    public double izracunaj() {
        return getLevi().izracunaj() + getDesni().izracunaj();
    }

    @Override
    public Izraz klon() {
        return new Sabiranje(this);
    }

    @Override
    public String toString() {
        return getLevi().toString() + " + " + getDesni().toString();
    }
}
