import java.util.Date;

public class Datum {

    private int dan, mesec, godina;

    public Datum(int dan, int mesec, int godina) {
        this.dan = dan;
        this.mesec = mesec;
        this.godina = godina;
    }

    public Datum(Datum d){
        this(d.dan, d.mesec, d.godina);
    }

    public int getDan() {
        return dan;
    }

    public void setDan(int dan) {
        this.dan = dan;
    }

    public int getMesec() {
        return mesec;
    }

    public void setMesec(int mesec) {
        this.mesec = mesec;
    }

    public int getGodina() {
        return godina;
    }

    public void setGodina(int godina) {
        this.godina = godina;
    }

    @Override
    public String toString() {
        return dan + "." + mesec + "." + godina + ".";
    }
}
