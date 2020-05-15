package Geometrija;

public class Main {

    public static void main(String[] args) {

        Pravougaonik pravougaonik = new Pravougaonik(10, 20, 100, 200);
        Kvadrat kvadrat = new Kvadrat(new Tacka(2, 3), 40);
        Krug krug = new Krug(40);
        Elipsa elipsa = new Elipsa(new Tacka(), 11, 42);
        Trougao trougao = new Trougao(10, 10, 20, 20, 40, 40);

        System.out.println(pravougaonik);
        System.out.println(kvadrat);
        System.out.println(krug);
        System.out.println(elipsa);
        System.out.println(trougao);
        System.out.println("-------------------------------------");

        Tacka centar = krug.getCentar();
        System.out.println("Krug se nalazi u tacki: " + centar);
        System.out.println("-------------------------------------");

        System.out.println("Duzine stranica trougla: AB = " + trougao.getAB() +
                            " BC = " + trougao.getBC() + " CA = " + trougao.getCA());
        System.out.println("-------------------------------------");

        // Translacija Oblika-a
        Tacka c1 = new Tacka(krug.getCentar());
        krug.getCentar().translate(10, 20);
        Tacka c2 = krug.getCentar();
        System.out.println("Krug je transliran iz " + c1 + " u " + c2);
        System.out.println("-------------------------------------");

        // Rastojanje izmedju centara 2 Oblik-a
        double dist = krug.getCentar().distance(kvadrat.getCentar());
        System.out.println("Rastojanje izmedju " + krug + " i " + kvadrat + " je " + dist);
    }
}
