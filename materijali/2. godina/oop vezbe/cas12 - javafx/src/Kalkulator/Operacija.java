package Kalkulator;

public enum Operacija {

    SABIRANJE('+'),
    ODUZIMANJE('-'),
    MNOZENJE('*'),
    DELJENJE('/'),
    KOREN('√');

    private char simbol;

    private Operacija(char simbol) {
        this.simbol = simbol;
    }

    @Override
    public String toString() {
        return "" + simbol;
    }
}
