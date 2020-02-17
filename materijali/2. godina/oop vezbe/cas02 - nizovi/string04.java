public class string04 {
    // Prebrojavanje datog podstringa u stringu

    public static void main(String[] args) {
        String DNK = "ggcgatatgcagtagcgcttctatgccataccgtatgctacacaacgtgatgcggccacttaggggcttctgtaagcgagt";
        String podstring = "atgc";

        int broj = brojac(DNK, podstring);
        System.out.println(broj);
    }

    static int brojac(String DNK, String podstring){
        int br = 0;
        // indeks prvog pojavljivanja podstringa:
        int i = DNK.indexOf(podstring);

        while (i != -1){
            br++; // ako smo u petlji, postoji bar 1 pojavljivanje
            // odbacujemo deo koji smo pretrazili:
            DNK = DNK.substring(i + podstring.length());
            i = DNK.indexOf(podstring);
        }
        return br;
    }
}
