public class Main {

    public static void main(String[] args) {
        Platforma p1 = new Platforma("ArchLinux", 8000.0, 20.0);
        Platforma p2 = new Platforma("Windows 10", 10000.0, 30.0);

        Platforma[] platforme = {p1, p2};

        System.out.println("Dostupne platforme:");
        for (Platforma p : platforme)
            System.out.println(p);
    }
}
