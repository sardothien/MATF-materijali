public class TestEntitet {

    public static void main(String[] args) {
        PokretniEntitet pe = new PokretniEntitet(0, 0, 100, 1, 0);
        Igrac igrac = new Igrac("test", 10000, pe);

        PokretniEntitet[] pokretniEntitet = {pe, igrac};

        // ispis pre pomeranja
        for (PokretniEntitet p: pokretniEntitet) {
            System.out.println(p);
            p.pomeriSe();
        }
        System.out.println();

        // ispis posle pomeranja
        for (PokretniEntitet p: pokretniEntitet)
            System.out.println(p);

    }
}
