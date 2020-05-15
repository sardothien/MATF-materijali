package Covek;

public class Covek implements Srpski, Engleski {

    private String ime, prezime;
    private int godine;

    public Covek(String ime, String prezime, int godine) {
        this.ime = ime;
        this.prezime = prezime;
        this.godine = godine;
    }

    public String getIme() {
        return ime;
    }

    public int getGodine() {
        return godine;
    }

    @Override
    public String toString() {
        return ime + " " + prezime + " godine: " + godine;
    }

    @Override
    public void hello() {
        System.out.println("Hello :)");
    }

    @Override
    public void goodbye() {
        System.out.println("Goodbye!");
    }

    @Override
    public void thanks() {
        System.out.println("Thank you.");
    }

    @Override
    public void zdravo() {
        System.out.println("Zdravo :)");
    }

    @Override
    public void dovidjenja() {
        System.out.println("Dovidjenja!");
    }

    @Override
    public void hvala() {
        System.out.println("Hvala.");
    }
}
