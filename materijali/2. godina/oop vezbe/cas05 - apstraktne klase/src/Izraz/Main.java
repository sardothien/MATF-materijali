package Izraz;

public class Main {

    public static void main(String[] args) {
        Izraz i1 = getExample1();
        System.out.println(i1 + " = " + i1.izracunaj());
        System.out.println("----------------------------------");

        Izraz i2 = getExample2();
        System.out.println(i2 + " = " + i2.izracunaj());
        System.out.println("----------------------------------");

        Izraz i3 = getExample3();
        System.out.println(i3 + " = " + i3.izracunaj());
        System.out.println("----------------------------------");
    }

    public static Izraz getExample3() {
        Broj b = new Broj(2);
        Promenljiva x = new Promenljiva("x", 2);
        Promenljiva y = new Promenljiva("y", 3);
        Mnozenje m1 = new Mnozenje(b, x);
        Mnozenje m2 = new Mnozenje(b, y);
        Sabiranje s = new Sabiranje(m1, m2);
        return s;
    }

    public static Izraz getExample2() {
        Broj b1 = new Broj(1);
        Broj b2 = new Broj(2);
        Broj b3 = new Broj(3);
        Mnozenje m = new Mnozenje(b1, b2);
        Sabiranje s = new Sabiranje(m, b3);
        return s;

    }

    public static Izraz getExample1() {
        Broj b1 = new Broj(2);
        Broj b2 = new Broj(3);
        Sabiranje s = new Sabiranje(b1, b2);
        return s;
    }
}
