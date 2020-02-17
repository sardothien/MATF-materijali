public abstract class Ljubimac {

    private String ime;
    private int starost;
    private String id;

    public Ljubimac(String ime, int starost) {
        this.ime = ime;
        this.starost = starost;
    }

    public Ljubimac(String ime, int starost, String id) {
        this.ime = ime;
        this.starost = starost;
        this.id = id;
    }

    public String getIme() {
        return ime;
    }

    public int getStarost() {
        return starost;
    }

    public String getId() {
        return id;
    }

    public abstract String generisiIdentifikaciju();

    @Override
    public String toString() {
        return "#" + id + " Ime: " + ime + ", starost: " + starost;
    }
}
