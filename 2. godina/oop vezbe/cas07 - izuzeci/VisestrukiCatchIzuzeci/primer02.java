package VisestrukiCatchIzuzeci;

import java.util.Scanner;

public class primer02 {
    public static void main(String[] args) {
        int x = 10;
        int[] a = {1, 2, 3, 4, 5};
        Scanner sc = null;

        try {
            sc.nextLine(); // NullPointerException
            x = 10/0;      // ArithmeticException
        }
        catch (ArithmeticException | ArrayIndexOutOfBoundsException e){
            System.out.println("Desila se 1 od 2 greske.");
        }
        catch (Exception e){
            System.out.println("Doslo je do neke druge greske.");
            System.out.println("Greska: " + e.getMessage());
            e.printStackTrace();
        }
        finally { // uvek se izvrsava; zatvara koriscene resurse
            if(sc != null)
                sc.close();
        }
    }
}
