import java.util.Arrays;

public class string07 {
    // Ilustracija sortiranja Stringa (sortiranje karaktera)

    public static void main(String[] args) {
        String str = "The quick brown fox jumps over the lazy dog!";
        System.out.println(str);

        char[] tmp = str.toCharArray();
        Arrays.sort(tmp);

        String sorted = new String(tmp); // = String.valueOf(tmp);
        System.out.println(sorted);
    }
}
