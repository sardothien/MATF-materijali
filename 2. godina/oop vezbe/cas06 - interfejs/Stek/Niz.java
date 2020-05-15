package Stek;

import java.util.Arrays;

public class Niz implements Stek {

    private int[] elementi;
    private int vrh, kapacitet;

    public Niz(){
        this(10);
    }

    public Niz(int kapacitet) {
        this.kapacitet = kapacitet;
        vrh = 0;
        elementi = new int[kapacitet];
    }

    public int getKapacitet() {
        return kapacitet;
    }

    @Override
    public int pop() {
        if(vrh == 0){
            System.err.println("Stack underflow!");
            return 0;
        }
        vrh--;
        return elementi[vrh];
    }

    @Override
    public void push(int x) {
        if(vrh == kapacitet){
            kapacitet *= 2;
            elementi = Arrays.copyOf(elementi, kapacitet);
        }
        elementi[vrh] = x;
        vrh++;
    }

    @Override
    public int top() {
        if(vrh == 0){
            System.err.println("Stack underflow!");
            return 0;
        }
        return elementi[vrh-1];
    }

    @Override
    public void show() {
        System.out.println("Sadrzaj: [ " + toString() + "]");
    }

    @Override
    public int size() {
        return vrh;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < vrh; i++)
            sb.append(elementi[i]).append(" ");
        return sb.toString();
    }
}
