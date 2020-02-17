import java.util.Scanner;

public class string03 {
    // Program pokazuje modifikaciju Stringa
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Unesite liniju teksta:");
        String ulaz = sc.nextLine();

        String mSlova = uMalaSlova(ulaz);
        System.out.println("Mala slova: " + mSlova);

        String vSlova = ulaz.toUpperCase();

        String vSlovaBezBelina = vSlova.replace(" ", "");
        System.out.println("Velika slova bez belina: " + vSlovaBezBelina);

        System.out.println("Uneta linija: " + ulaz);
    }

    static String uMalaSlova(String t){
        // Stringovi su imutabilni!
        char[] tmp = t.toCharArray();
        for (int i = 0; i < tmp.length; i++)
            if(Character.isUpperCase(tmp[i]))
                tmp[i] = Character.toLowerCase(tmp[i]);

        // Vraca stringovnu reprezentaciju od tmp
        return String.valueOf(tmp);
    }
}
