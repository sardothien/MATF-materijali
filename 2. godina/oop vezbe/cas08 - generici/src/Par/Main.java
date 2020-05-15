package Par;

public class Main {

    public static void main(String[] args) {

        UredjeniPar<String, Integer> p = new UredjeniPar<>("Python", 100);
        UredjeniPar<String, Integer> q = dveVrednosti();

        System.out.println(p);
        System.out.println(q);
    }

    private static UredjeniPar<String, Integer> dveVrednosti() {
        return new UredjeniPar<>("Java", 90);
    }
}
