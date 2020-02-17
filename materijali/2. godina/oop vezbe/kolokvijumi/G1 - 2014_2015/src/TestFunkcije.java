import java.util.Scanner;

public class TestFunkcije {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite a:");
        int a = sc.nextInt();
        System.out.println("Unesite b:");
        int b = sc.nextInt();

        Clan clan = new Clan(a, b);

        System.out.println(clan.toString());

        sc.close();
    }
}
