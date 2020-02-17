import java.util.Scanner;

public class zadatak01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite string:");
        String recenica = sc.nextLine();

        recenica = ispisi(recenica);
        System.out.println("Promenjen string: " + recenica);
    }

    static String ispisi(String recenica){
        char[] tmp = recenica.toCharArray();

        for (int i = 0; i < tmp.length; i++) {
            if(Character.isUpperCase(tmp[i]))
                tmp[i] = Character.toLowerCase(tmp[i]);
            else if(Character.isLowerCase(tmp[i]))
                tmp[i] = Character.toUpperCase(tmp[i]);
        }

        return String.valueOf(tmp);
    }
}