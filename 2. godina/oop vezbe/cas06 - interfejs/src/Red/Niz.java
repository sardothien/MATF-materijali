package Red;

public class Niz implements Red {

    private int kapacitet = 1025;
    private int[] xs = new int[kapacitet];
    private int pocetak, kraj, broj;


    @Override
    public void add(int x) {
        if (broj == kapacitet-1){
            System.err.println("Queue overflow!");
            return;
        }
        xs[kraj] = x;
        broj++;
        kraj = (kraj+1) % kapacitet;
    }

    @Override
    public int remove() {
        if (broj == 0){
            System.err.println("Queue underflow!");
            return 0;
        }
        int tmp = xs[pocetak];
        pocetak = (pocetak+1) % kapacitet;
        broj--;
        return tmp;
    }

    @Override
    public int head() {
        if(broj == 0){
            System.err.println("Queue underflow!");
            return 0;
        }
        return xs[pocetak];
    }

    @Override
    public int back() {
        if(broj == 0){
            System.err.println("Queue underflow!");
            return 0;
        }
        if (kraj == 0)
            return xs[kapacitet-1];
        else
            return xs[kraj-1];
    }

    @Override
    public int size() {
        return broj;
    }

    @Override
    public void show() {
        System.out.print("[ ");
        int i = pocetak;
        while (i != kraj){
            System.out.print(xs[i] + " ");
            i = (i+1) % kapacitet;
        }
        System.out.println("]");
    }
}
