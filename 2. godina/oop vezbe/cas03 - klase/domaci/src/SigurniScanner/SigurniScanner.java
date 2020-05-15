package SigurniScanner;

import java.util.Scanner;

public class SigurniScanner {

    private Scanner sc;

    // Konstruktor
    public SigurniScanner(Scanner sc) {
        this.sc = sc;
        // TODO: instancira sc i vezuje ga na System.in
    }

    // Metode
    public int sledeciInt(){
        if(sc.hasNextInt())
            return sc.nextInt();
        else {
            System.out.println("Ne postoji sledeci int");
            return 1;
        }
    }

    public double sledeciDouble(){
        if(sc.hasNextDouble())
            return sc.nextDouble();
        else {
            System.out.println("Ne postoji sledeci double");
            return 1;
        }
    }

    public String sledecaRec(){
        if(sc.hasNext())
            return sc.next();
        else {
            System.out.println("Ne postoji sledeca rec");
            return null;
        }
    }

    public String sledecaLinija(){
        if(sc.hasNextLine())
            return sc.nextLine();
        else {
            System.out.println("Ne postoji sledeca linija");
            return null;
        }
    }

    public char sledeciKarakter(){
        if(sc.hasNext())
            return sc.next().charAt(0);
        else {
            System.out.println("Ne postoji sledeci karakter");
            return 1;
        }
    }


}
