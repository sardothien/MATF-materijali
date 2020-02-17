package IzrazKloniranje;

public class Mnozenje extends BinarnaOperacija {
    public Mnozenje(Izraz levi, Izraz desni) {
        super(levi, desni);
    }

    public Mnozenje(Mnozenje m) {
        super(m.getLevi(), m.getDesni());
    }

    @Override
    public double izracunaj() {
        return getLevi().izracunaj() * getDesni().izracunaj();
    }

    @Override
    public Izraz klon() {
        return new Mnozenje(this);
    }

    @Override
    public String toString() {
        return getLevi().toString() + " * " + getDesni().toString();
    }
}
