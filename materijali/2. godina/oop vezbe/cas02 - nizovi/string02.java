import java.util.Scanner;

public class string02 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite liniju teksta:");
        String ulaz = sc.nextLine();

        int brSlova = 0, brCifara = 0, brBelina = 0;
        for (int i = 0; i < ulaz.length(); i++) {
            if(Character.isDigit(ulaz.charAt(i)))
                brCifara++;
            else if(Character.isLetter(ulaz.charAt(i)))
                brSlova++;
            else if(Character.isWhitespace(ulaz.charAt(i)))
                brBelina++;
        }

        System.out.println("Broj slova: " + brSlova);
        System.out.println("Broj cifara: " + brCifara);
        System.out.println("Broj belina: " + brBelina);
    }
}
