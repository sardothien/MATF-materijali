import java.util.Scanner;

public class zadatak02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite ceo broj (string):");
        String sBroj = sc.next();

        int broj = Integer.parseInt(sBroj);
        System.out.println(broj*broj);

        sc.close();
    }
}
