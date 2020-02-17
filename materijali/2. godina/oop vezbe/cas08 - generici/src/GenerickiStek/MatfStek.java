package GenerickiStek;

public class MatfStek<T> implements GenerickiStek<T> {
    @Override
    public T top() {
        if(koren == null)
            throw new PotkoracenjeSteka();

        Cvor<T> c = koren;
        return c.vrednost;
    }

    @Override
    public T pop() {
        if(koren == null)
            throw new PotkoracenjeSteka();

        Cvor<T> c = koren;
        koren = koren.sledeci;
        return c.vrednost;
    }

    @Override
    public void push(T vr) {
        Cvor c = new Cvor<>(vr);
        c.sledeci = koren;
        koren = c;
    }

    private class Cvor<G>{
        G vrednost;
        Cvor<G> sledeci;

        Cvor(G vrednost){
            this.vrednost = vrednost;
        }

        @Override
        public String toString() {
            return vrednost.toString();
        }
    }

    private Cvor<T> koren;

    public MatfStek(){
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");

        Cvor<T> iterator = koren;
        while(iterator != null){
            sb.append(iterator.vrednost).append(" ");
            iterator = iterator.sledeci;
        }

        sb.append("]");

        return sb.toString();
    }
}
