import java.util.Scanner;

public class Karakteri {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char x = 'x';
        if(sc.hasNext()){
            String tmp = sc.next();
            x = tmp.charAt(0);
        }
        else {
            System.out.println("Nije uneta rec ili karakter!");
            System.exit(1);
        }

        System.out.println("Unet je karakter: " + x);

        if(Character.isUpperCase(x)){
            System.out.println(x + " je veliko slovo");
            System.out.println("Mozemo ga zapisati i kao malo: " + Character.toLowerCase(x));
        }
        else if(Character.isLowerCase(x)){
            System.out.println(x + " je malo slovo");
            System.out.println("Mozemo ga napisati kao veliko: " + Character.toUpperCase(x));
        }
        else if(Character.isDigit(x)){
            System.out.println(x + " je cifra");
            int y = Character.getNumericValue(x);
            System.out.println("Numericka vrednost cifre: " + y);
        }

        sc.close();
    }
}
