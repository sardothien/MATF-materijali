package primer02;

public class Main {
    public static void main(String[] args) {
        Tacka t1 = new Tacka(0, 0);
        Tacka t2 = new Tacka(2, 2);

        System.out.println("t1: " + t1);
        System.out.println("t2: " + t2);

        t1.transliraj(2, 2);

        if(t1.equals(t2))
            System.out.println("t1 == t2");
        else
            System.out.println("t1 != t2");

        t1.transliraj(-2, -2);
        double d = t1.distance(t2);
        System.out.println("d(t1, t2) = " + d);
    }
}
