package Izraz;

public class Mnozenje extends BinarnaOperacija {
    public Mnozenje(Izraz levi, Izraz desni) {
        super(levi, desni);
    }

    @Override
    public double izracunaj() {
        return getLevi().izracunaj() * getDesni().izracunaj();
    }

    @Override
    public String toString() {
        return getLevi().toString() + " * " + getDesni().toString();
    }
}
