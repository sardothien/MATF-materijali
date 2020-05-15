public enum TipVeze {
    JEDNOSTRUKA(1),
    DVOSTRUKA(2),
    TROSTRUKA(3);

    private int brParovaE;

    TipVeze(int brParovaE) {
        this.brParovaE = brParovaE;
    }

    public int getBrParovaE() {
        return brParovaE;
    }
}
