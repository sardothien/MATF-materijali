import java.util.Arrays;

public class klasaArrays01 {
    // Primer upotrebe fje za sortiranje i binarne pretrage
    public static void main(String[] args) {
        int[] a = {10, 5, 3, 1, 7, 4, 2, 9, 6, 8};

        Arrays.sort(a);
        System.out.println("Sortirani niz: " + Arrays.toString(a));

        // Binarna pretraga
        int x = 43;
        int  i = Arrays.binarySearch(a, x);

        if(i < 0)
            System.out.println("Element " + x + " ne postoji u nizu.");
        else
            System.out.println("Element " + x + " se nalazi u nizu, na poziciji " + i);
    }
}
