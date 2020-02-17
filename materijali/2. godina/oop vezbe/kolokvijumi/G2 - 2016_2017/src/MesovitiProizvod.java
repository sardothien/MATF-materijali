public class MesovitiProizvod extends VektorOperacija {

    private Vektor v1, v2, v3;

    public MesovitiProizvod(Vektor v1, Vektor v2, Vektor v3) {
        this.v1 = v1;
        this.v2 = v2;
        this.v3 = v3;
    }

    public Vektor getV1() {
        return v1;
    }

    public Vektor getV2() {
        return v2;
    }

    public Vektor getV3() {
        return v3;
    }

    @Override
    public double izracunaj() {
        Vektor t = vektorskiProizvod(v2, v3);
        return v1.getX()*t.getX() + v1.getY()*t.getY() + v1.getZ()*t.getZ();
    }

    @Override
    public String toString() {
        return "(" + v1.getX() + ", " + v1.getY() + ", " + v1.getZ() + ")" +
                " . " + "(" +
                "(" + v2.getX() + ", " + v2.getY() + ", " + v2.getZ() + ")" +
                "x" +
                "(" + v3.getX() + ", " + v3.getY() + ", " + v3.getZ() + ")" +
                ") = " + izracunaj();
    }
}
