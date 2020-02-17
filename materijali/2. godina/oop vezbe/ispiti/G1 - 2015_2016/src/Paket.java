public abstract class Paket {

    public abstract char vrsta();
    public abstract double zapremina();
    public abstract double povrsina();

    public String toString(){
        return Character.toString(vrsta());
    }
}
