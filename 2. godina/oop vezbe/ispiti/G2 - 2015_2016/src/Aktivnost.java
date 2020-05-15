public enum Aktivnost {
    S,           // Sedeci
    M,  // Umereno aktivan
    A,          // Aktivan
    VA;    // Veoma aktivan

    @Override
    public String toString() {
        switch (this){
            case S: return "sedeci";
            case M: return "umereno aktivan";
            case A: return "aktivan";
            case VA: return "veoma aktivan";
            default: return "";
        }
    }
}
