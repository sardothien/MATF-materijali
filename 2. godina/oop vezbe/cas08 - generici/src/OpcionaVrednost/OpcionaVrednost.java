package OpcionaVrednost;

import java.util.Objects;

public class OpcionaVrednost<T> {

    private T vrednost;

    private static OpcionaVrednost<?> EMPTY = new OpcionaVrednost<>();

    public static <T> OpcionaVrednost<T> od(T vrednost){
        return new OpcionaVrednost<>(vrednost);
    }

    public static <T> OpcionaVrednost<T> prazan(){
        OpcionaVrednost<T> tmp = (OpcionaVrednost<T>) EMPTY;
        return tmp;
    }

    public static <T> OpcionaVrednost<T> odMozdaNepostojece(T vrednost){
        return vrednost == null ? prazan() : od(vrednost);
    }

    private OpcionaVrednost(T vrednost){
        Objects.requireNonNull(vrednost, "Vrednost ne sme biti null!");
        this.vrednost = vrednost;
    }

    public OpcionaVrednost() {
    }

    public boolean postoji(){
        return vrednost != null;
    }

    public T getVrednost() {
        return vrednost;
    }

    @Override
    public String toString() {
        if(postoji())
            return vrednost.toString();
        else
            return "{}";
    }
}
