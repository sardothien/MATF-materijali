package Red;

public enum Operacija {
    ADD_OPERACIJA(0),
    REMOVE_OPERACIJA(1),
    HEAD_OPERACIJA(2),
    BACK_OPERACIJA(3),
    SIZE_OPERACIJA(4),
    EXIT_OPERACIJA(5);

    public static Operacija fromInt(int op){
        switch (op){
            case 0: return ADD_OPERACIJA;
            case 1: return REMOVE_OPERACIJA;
            case 2: return HEAD_OPERACIJA;
            case 3: return BACK_OPERACIJA;
            case 4: return SIZE_OPERACIJA;
            case 5: return EXIT_OPERACIJA;
            default: return EXIT_OPERACIJA;
        }
    }

    private final int op;

    private Operacija(int op){
        this.op = op;
    }
}
