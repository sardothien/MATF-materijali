public class Rastojanje {

    public static double izracunajRastojanje(Podatak p1, Podatak p2){
        int v = (p1.getVisina() - p2.getVisina())*(p1.getVisina() - p2.getVisina());
        int t = (p1.getTezina() - p2.getTezina())*(p1.getTezina() - p2.getTezina());

        return Math.sqrt(v + t);
    }
}
