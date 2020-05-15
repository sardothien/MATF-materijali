import java.util.Scanner;

public class string10 {
    // Da li je uneti string palindrom?

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Unesite string za proveru:");
        String str = sc.nextLine();

        if(palindrom(str))
            System.out.println("Uneti string jeste palindrom.");
        else
            System.out.println("Uneti string nije palindrom.");
        sc.close();
    }

    public static boolean palindrom(String str){
        String mSlovaBezBelina = str.replace(" ", "").toLowerCase();
        return new StringBuilder(mSlovaBezBelina).reverse().toString().equals(mSlovaBezBelina);
    }
}
