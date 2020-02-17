import java.util.*;
import java.util.function.Consumer;

public class AlternirajuciIterabilni<T> implements Iterable<T> {

    private List<Iterable<T>> sadrzaj;

    public AlternirajuciIterabilni(Iterable<T>... grupe){
        sadrzaj = Arrays.asList(grupe);
    }


    @Override
    public Iterator<T> iterator() {
        return new AlternirajuciIterator();
    }

    private class AlternirajuciIterator implements Iterator<T> {
        private int indeks = -1;
        private List<Iterator<T>> lista;

        public AlternirajuciIterator() {
            lista = new ArrayList<>(sadrzaj.size());
            for (Iterable<T> it : sadrzaj)
                lista.add(it.iterator());
        }

        @Override
        public boolean hasNext() {
            for (Iterator<T> it : lista)
                if (it.hasNext())
                    return true;
            return false;
        }

        @Override
        public T next() {
            if (hasNext()){
                T rez;
                while (true){
                    indeks = (indeks+1) % lista.size();
                    if (lista.get(indeks).hasNext()){
                        rez = lista.get(indeks).next();
                        break;
                    }
                }
                return rez;
            }
            else
                throw new NoSuchElementException();
        }
    }
}
