package IzrazKloniranje;

public abstract class BinarnaOperacija extends Izraz {
    private Izraz levi, desni;

    public BinarnaOperacija(Izraz levi, Izraz desni) {
        this.levi = levi.klon();
        this.desni = desni.klon();
    }

    public Izraz getLevi() {
        return levi;
    }

    public Izraz getDesni() {
        return desni;
    }
}
