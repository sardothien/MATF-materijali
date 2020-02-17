public class TestTarotKarta {

    public static void main(String[] args) {
        TarotKarta tk1 = new TarotKarta(0, "Visoka Svestenica", "Italija");
        TarotKarta tk2 = new TarotKarta(1, "Lazov", "Otomansko Carstvo");
        TarotKarta tk3 = new TarotKarta(-1, "Mag", "Nemacka");

        TarotKarta[] karte = {tk1, tk2, tk3};
        for (TarotKarta karta : karte) {
            System.out.println(karta.toString());
        }
    }
}
