package Set;

import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class PoligonalnaLinija {

    private Set<Tacka> temena;

    private Set<Tacka> napraviSkup(){
        return new TreeSet<>();
    }

    public PoligonalnaLinija() {
        temena = napraviSkup();
    }

    public PoligonalnaLinija(Tacka teme) {
        temena = napraviSkup();
        temena.add(new Tacka(teme));
    }

    public PoligonalnaLinija(double[][] koordinate){
        temena = napraviSkup();
        for (double[] teme: koordinate)
            temena.add(new Tacka(teme[0], teme[1]));
    }

    public int getBrojTemena(){
        return temena.size();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Iterator<Tacka> it = temena.iterator();
        while (it.hasNext())
            sb.append(it.next() + " ");
        return sb.toString();
    }
}
