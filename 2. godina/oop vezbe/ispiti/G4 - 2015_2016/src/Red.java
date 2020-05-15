import java.util.LinkedList;

public class Red {

    private LinkedList<Ljubimac> lista;

    public Red() {
        this.lista = new LinkedList<>();
    }

    public void dodajURed(Ljubimac ljubimac){
        lista.add(ljubimac);
    }

    public Ljubimac prozoviSledeceg(){
        return lista.poll();
    }

    @Override
    public String toString() {

        StringBuilder sb = new StringBuilder();
        int i = 1;
        for(Ljubimac ljubimac : lista)
            sb.append(i++ + ": " + ljubimac + "\n");

        return sb.toString();
    }
}
