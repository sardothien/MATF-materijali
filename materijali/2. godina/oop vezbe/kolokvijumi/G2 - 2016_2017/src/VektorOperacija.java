public abstract class VektorOperacija {

    public abstract double izracunaj();

    public static Vektor vektorskiProizvod(Vektor u, Vektor t){
        double x = u.getY()*t.getZ() - u.getZ()*t.getY();
        double y = u.getZ()*t.getX() - u.getX()*t.getZ();
        double z = u.getX()*t.getY() - u.getY()*t.getX();

        Vektor v = new Vektor(x, y, z);
        return v;
    }
}
