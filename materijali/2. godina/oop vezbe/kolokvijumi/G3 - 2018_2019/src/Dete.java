public class Dete {

    private String ime;
    private Hrana[] jela;

    public Dete(String ime) {
        this.ime = ime;
        this.jela = new Hrana[4];
    }

    public String getIme() {
        return ime;
    }

    public Hrana[] getJela() {
        return jela;
    }

    private int i = -1;

    public void dodajJelo(Hrana hr){
        if(i == 4)
            return;
        i++;
        jela[i] = hr;

    }

    @Override
    public String toString() {
        if(i == -1)
            return "[Dete] ime: " + ime + "\n" + "nema jela";
        else{
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < jela.length-1; j++) {
                sb.append(jela[j]).append("\n");
            }
            return "[Dete] ime: " + ime + "\n" + "jela:\n" + sb.toString();
        }
    }
}
