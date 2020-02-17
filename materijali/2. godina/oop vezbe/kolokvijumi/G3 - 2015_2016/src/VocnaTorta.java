public class VocnaTorta extends ReceptTorta {
    private String voce;
    private static int brojVocnihTorti;

    public VocnaTorta(Sastojak[] sastojci, int nivoTezine, String voce) {
        super(sastojci, nivoTezine);
        this.voce = voce;
        brojVocnihTorti++;
    }

    public VocnaTorta(VocnaTorta v){
        super(v.getSastojci(), v.getNivoTezine());
        voce = v.voce;
    }

    public static int getBrojVocnihTorti() {
        return brojVocnihTorti;
    }

    @Override
    public String toString() {
        return super.toString() + '\n' + '\n' +
                "Masa torte: " + super.ukupnaMasaTorte() + "g\n" +
                "Voce: " + voce + '\n';
    }
}
