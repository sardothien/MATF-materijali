public abstract class Sifrar {

    private Poruka poruka;

    public abstract Poruka sifruj();

    public Sifrar(Poruka poruka) {
        this.poruka = poruka;
    }

    public Poruka getPoruka() {
        return poruka;
    }
}
