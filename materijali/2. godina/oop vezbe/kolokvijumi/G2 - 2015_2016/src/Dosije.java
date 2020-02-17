public class Dosije {

    private String imeIPrezime;
    private String jmbg;

    public Dosije(String imeIPrezime, String jmbg) {
        this.imeIPrezime = imeIPrezime;
        this.jmbg = jmbg;
    }

    public Dosije(Dosije d){
        this(d.imeIPrezime, d.jmbg);
    }

    public String getImeIPrezime() {
        return imeIPrezime;
    }

    public void setImeIPrezime(String imeIPrezime) {
        this.imeIPrezime = imeIPrezime;
    }

    public String getJmbg() {
        return jmbg;
    }

    public void setJmbg(String jmbg) {
        this.jmbg = jmbg;
    }

    public static boolean jesteJmbg(String jmbg){
        if(jmbg.length() != 13){
            System.out.println("Jmbg nije duzine 13!");
            return false;
        }

        else{
            for (int i = 0; i < jmbg.length(); i++) {
                if(!Character.isDigit(jmbg.charAt(i))) {
                    System.out.println("Jmbg nije broj!");
                    return false;
                }
            }
            return true;
        }
    }

    @Override
    public String toString() {
        return imeIPrezime + '\n' +
                "jmbg: " + jmbg;
    }
}
