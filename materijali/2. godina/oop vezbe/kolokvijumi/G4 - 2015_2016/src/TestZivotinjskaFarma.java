import java.util.Scanner;

public class TestZivotinjskaFarma {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Svinja svinja = new Svinja("Napoleon");

        System.out.println("Broj parola za Moli:");
        int brParola = sc.nextInt();
        String[] parole = new String[brParola];
        for (int i = 0; i < brParola; i++)
            parole[i] = sc.next();

        Ovca moli = new Ovca("Moli", parole);

        System.out.println("Broj parola za Poli:");
        brParola = sc.nextInt();
        parole = new String[brParola];
        for (int i = 0; i < brParola; i++)
            parole[i] = sc.next();

        Ovca poli = new Ovca("Poli", parole);

        System.out.println(svinja);
        System.out.println();

        moli.uglas();
        poli.uglas();

        System.out.println("Poli menja parolu:");
        poli.naredi(new Direktiva("Poli", "CETIRI NOGE DOBRE, DVE NOGE BOLJE!"));
        System.out.println(poli);

        System.out.println("Napoleon menja parolu:");
        svinja.setParola("Sve svinje su jednake, ali su neke jednakije od drugih.");
        System.out.println(svinja);

        sc.close();
    }
}
