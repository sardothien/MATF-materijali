package Stek;

public enum Operacija {
    PUSH_OPERACIJA(0),
    POP_OPERACIJA(1),
    TOP_OPERACIJA(2),
    SIZE_OPERACIJA(3),
    EXIT_OPERACIJA(4);

    private final int op;

    private Operacija(int op){
        this.op = op;
    }
}
