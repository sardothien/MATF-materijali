import java.util.Scanner;

public class string08 {
    // Koriscenje klase StringBuilder

    public static void main(String[] args) {
        // Unosimo rec po rec i zelimo da napravimo 1 string
        // koji ih sve sadrzi (unos do reci exit).
        StringBuilder sb = new StringBuilder();
        Scanner sc = new Scanner(System.in);

        String ulaz = sc.next();
        while (!ulaz.equals("exit")){
            sb.append(ulaz + " ");
            ulaz = sc.next();
        }

      /*  String izlaz = sb.toString();
          System.out.println(izlaz);    */
        System.out.println(sb);
    }
}
