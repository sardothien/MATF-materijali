public class TestZvucnik {

    public static void main(String[] args) {
        Zvucnik z1 = new Zvucnik("Yamaha", "HS8", 75);
        Zvucnik z2 = new Zvucnik("Yamaha", "HS7", 60);
        Zvucnik z3 = new Zvucnik("Logitec", "Z313", 25);

        Zvucnik[] zvucnici = {z1, z2, z3};
        for(Zvucnik z : zvucnici){
            System.out.println(z);
            System.out.println("-------------------------------------");
        }
    }
}
