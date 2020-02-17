package OpcionaVrednost;

public class Main {

    public static void main(String[] args) {
        primer1();
        System.out.println("--------------------------------------");
        primer2();
    }

    private static void primer2() {
        Integer[] xs = {1, 2, 3, 4, 100, 40, 20};
        OpcionaVrednost<Integer> maksX = nadjiMax(xs);

        if(maksX.postoji())
            System.out.println("maksimum(xs) = " + maksX);
        else
            System.out.println("Prazan niz!");
    }

    private static <T extends Comparable<T>> OpcionaVrednost<T> nadjiMax(T[] xs) {
        if(xs.length == 0)
            return OpcionaVrednost.prazan();

        T max = null;
        boolean prvi = true;
        for (T x : xs) {
            if(prvi){
                max = x;
                prvi = false;
            }
            else if(x.compareTo(max) > 0)
                max = x;
        }

        return OpcionaVrednost.od(max);
    }

    private static void primer1() {
        OpcionaVrednost<String> rez = Poruka.procitajPoverljivuPoruku();

        if(rez.postoji())
            System.out.println("Citanje uspesno: " + rez.getVrednost());
        else
            System.out.println("Neuspelo citanje!");
    }
}
