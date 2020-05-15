package Izraz;

public abstract class BinarnaOperacija extends Izraz {

    private Izraz levi, desni;

    public BinarnaOperacija(Izraz levi, Izraz desni) {
        this.levi = levi;
        this.desni = desni;
    }

    public Izraz getLevi() {
        return levi;
    }

    public Izraz getDesni() {
        return desni;
    }
}
