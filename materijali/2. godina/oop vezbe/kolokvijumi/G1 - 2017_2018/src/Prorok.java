public class Prorok {

    private String ime;
    private int brOstavarenihProrocanstava;
    private int ukupanBrProrocanstava;

    public Prorok(String ime, int brOstavarenihProrocanstava, int ukupanBrProrocanstava) {
        this.ime = ime;
        this.brOstavarenihProrocanstava = brOstavarenihProrocanstava;
        this.ukupanBrProrocanstava = ukupanBrProrocanstava;
    }

    public Prorok(Prorok p) {
        this(p.ime, p.brOstavarenihProrocanstava, p.ukupanBrProrocanstava);
    }

    public String getIme() {
        return ime;
    }

    public int getBrOstavarenihProrocanstava() {
        return brOstavarenihProrocanstava;
    }

    public int getUkupanBrProrocanstava() {
        return ukupanBrProrocanstava;
    }

    void zabeleziIshodProrocanstva(boolean status){
        ukupanBrProrocanstava++;
        if(status)
            brOstavarenihProrocanstava++;
    }

    public float getProcenatUspesnosti(){
        return brOstavarenihProrocanstava*1.0f/ukupanBrProrocanstava*100.0f;
    }

    @Override
    public String toString() {
        return ime + ", uspelo: " +
                brOstavarenihProrocanstava + ", ukupno: " +
                ukupanBrProrocanstava;
    }
}
