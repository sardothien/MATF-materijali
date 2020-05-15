package GenerickiStek;

public class Main {

    public static void main(String[] args) {
        int n = 5;
        MatfStek<Tacka> tacke = new MatfStek<Tacka>();

        for (int i = 0; i < n; i++)
            tacke.push(new Tacka(i+1, (i+1)*10));

        System.out.println(tacke);

        System.out.println("Tacka na vrhu steka: " + tacke.top());
        Tacka t = tacke.pop();
        System.out.println("Skinuta tacka " + t + " sa vrha steka.");
        System.out.println("Tacka na vrhu steka: " + tacke.top());
    }
}
