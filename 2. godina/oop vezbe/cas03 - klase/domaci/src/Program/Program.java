package Program;

public class Program {

    private String sadrzaj;
    private String ime;
    private int minor;
    private int major;
    private double velicina;

    // Konstruktor
    public Program(String sadrzaj, String ime, int minor, int major, double velicina){
        this.sadrzaj = sadrzaj;
        this.ime = ime;
        this.minor = minor;
        this.major = major;
        this.velicina = velicina;
    }

    public int brojJedinicnihBitova(){
        int br = 0;
        char[] tmp = sadrzaj.toCharArray();
        for (int i = 0; i < tmp.length; i++) {
            if(tmp[i] == '1')
                br++;
        }
        return br;
    }

    public String getVerzija(){
        return major + "." + minor;
    }

    public double getVelicinaKilobajta(){
        return velicina * 1000;
    }

    public String getMasinskiKod(){
        return sadrzaj;
    }

    public void setMasinskiKod(String kod){
        this.sadrzaj = kod;
    }

    public String toString(){
        return "ime: " + ime + "\n" + "sadrzaj: " + sadrzaj + "\n" +
                "major: " + major + "\n" + "minor: " + minor + "\n" +
                "velicina: " + velicina + " MB";
    }
}
