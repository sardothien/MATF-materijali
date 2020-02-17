package NizIzuzeci;

import java.util.Arrays;

public class Niz {

    private int[] a;

    public Niz(int n){
        a = new int[n];
    }

    public Niz(int[] tmp){
        a = new int[tmp.length];
        for (int i = 0; i < tmp.length; i++)
            a[i] = tmp[i];
    }

    public int length(){
        return a.length;
    }

    public int get(int i){
        if(i < 0 || i >= a.length)
            throw new ArrayIndexOutOfBoundsException("Lose indeksiranje.");
        return a[i];
    }

    @Override
    public String toString() {
        return Arrays.toString(a);
    }
}
