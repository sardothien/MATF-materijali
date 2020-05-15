import jdk.nashorn.internal.runtime.FunctionScope;

import java.util.function.BinaryOperator;
import java.util.function.Function;

public class Primer07 {

    static Integer kvadrat(Integer x){
        return x*x;
    }

    static Boolean paran(Integer x){
        return x % 2 == 0;
    }

    static Integer dodaj(Integer x, Integer y){
        return x+y;
    }

    public static void main(String[] args) {
        Function<Integer, Integer> kvadrat1 = x -> x*x;
        Function<Integer, Boolean> paran1 = x -> x%2 == 0;
        BinaryOperator<Integer> dodaj1 = (x, y) -> x+y;

        System.out.println("2*2 = " + kvadrat1.apply(2));
        System.out.println("2 je paran: " + paran1.apply(2));
        System.out.println("2 + 3 = " + dodaj1.apply(2, 3));

        System.out.println();

        System.out.println("2*2 = " + kvadrat(2));
        System.out.println("2 je paran: " + paran(2));
        System.out.println("2 + 3 = " + dodaj(2, 3));
    }

}
