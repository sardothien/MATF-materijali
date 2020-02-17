package NizIzuzeci;

public class Main {

    public static void main(String[] args) {
        int[] tmp = {1, 2, 3, 4};
        Niz niz = new Niz(tmp);

        System.out.println("niz[2] = " + niz.get(2));

        try {
            System.out.println("niz[100] = " + niz.get(100));
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.err.println(e.getMessage());
            e.printStackTrace();
        }
    }
}
