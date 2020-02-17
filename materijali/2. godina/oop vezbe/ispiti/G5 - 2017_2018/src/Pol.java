public enum Pol {
    ZENSKI,
    MUSKI;

    public static Pol createFromString(String s){
        if (s.equals("z"))
            return Pol.ZENSKI;
        else
            return Pol.MUSKI;
    }
}
