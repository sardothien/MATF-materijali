package Geometrija;

public class Main {

    public static void main(String[] args) {
        Pravougaonik pravougaonik = new Pravougaonik();
        Kvadrat kvadrat = new Kvadrat(new Tacka(2,3), 10);
        Krug krug = new Krug();

        Povrsina[] povrsine = {pravougaonik, kvadrat, krug};
        for (Povrsina p: povrsine) {
            System.out.println(p.toString() + ":");
            System.out.println("P = " + p.getPovrsina());
            if (p instanceof Obim)
                System.out.println("O = " + ((Obim) p).getObim());
            System.out.println("--------------------------------------");
        }

        Duz duz = new Duz(new Tacka(), new Tacka(2,3));
    }
}
