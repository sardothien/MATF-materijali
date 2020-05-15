public class string09 {

    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        sb.append("Hello").append(" ").append("world.");
        sb.reverse();

        System.out.println("Obrnuti string: " + sb);
        System.out.println("Broj karaktera: " + sb.length());

        sb.setCharAt(0, '!');
        System.out.println("Izmenjeni string: " + sb);

        // Ciscenje StringBuilder-a
        sb.setLength(0);

        sb.append("Hello world");

        // Ubacivanje i brisanje podstringova
        sb.insert(6, "dear ");
        System.out.println("Posle ubacivanja: " + sb);
        sb.delete(6, 11);
        System.out.println("Nakon brisanja: " + sb);
    }

}
