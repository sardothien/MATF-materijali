import java.util.Scanner;

public class zadatak04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite 2 stringa:");
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();

        if(s1.equals(s2))
            System.out.println("Jednaki su!");
        else{
            if(s1.indexOf(s2) == -1)
                System.out.println("Nije podstring.");
            else
                System.out.println(s1.indexOf(s2));
        }


        sc.close();
    }
}
