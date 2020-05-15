import java.util.Scanner;

public class TestPoruka {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite tekst tajne poruke:");
        String tajna_poruka = sc.nextLine();
        Poruka poruka = new Poruka(tajna_poruka);
        //System.out.println(poruka.toString());

        System.out.println("Unesite tip sifrovanja(t ili r):");
        char tip = sc.next().charAt(0);

        Sifrar sifrar;

        if(tip == 't'){
            System.out.println("Unesite pomeraj:");
            int pomeraj = sc.nextInt();
            sifrar = new SifrarTranslacija(poruka, pomeraj);
        }
        else{
            System.out.println("Uneiste smer i broj mesta:");
            String smer = sc.next();
            int brMesta = sc.nextInt();
            sifrar = new SIfraRotacija(poruka, brMesta, smer);
        }

        System.out.println(sifrar.toString());
        Poruka sifrovana = sifrar.sifruj();
        System.out.println("Nakon odgovarajuceg sifrovanja:\n" + sifrovana);

        sc.close();
    }
}
