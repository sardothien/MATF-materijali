package Kutija;

public class Kutija<T> {

    private T predmet;
    private boolean sadrziPredmet;

    public Kutija() {
    }

    public Kutija(T predmet) {
        this.predmet = predmet;
        this.sadrziPredmet = true;
    }

    public T uzmiPredmet(){
        if(sadrziPredmet) {
            sadrziPredmet = false;
            return predmet;
        }
        else
            return null;
    }

    public void ubaciPredmet(T predmet){
        if(sadrziPredmet)
            System.out.println("Kutija je puna!");
        else{
            this.predmet = predmet;
            sadrziPredmet = true;
        }
    }

    @Override
    public String toString() {
        if(sadrziPredmet)
            return "[" + predmet.toString() + "]";
        else
            return "[ ]";
    }
}
