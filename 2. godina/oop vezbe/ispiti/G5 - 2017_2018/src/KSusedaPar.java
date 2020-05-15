public class KSusedaPar implements Comparable<KSusedaPar>{

    private int indeksUPodacima;
    private double rastojanje;

    public KSusedaPar(int indeksUPodacima, double rastojanje) {
        this.indeksUPodacima = indeksUPodacima;
        this.rastojanje = rastojanje;
    }

    public int getIndeksUPodacima() {
        return indeksUPodacima;
    }

    public double getRastojanje() {
        return rastojanje;
    }

    @Override
    public int compareTo(KSusedaPar o) {
        return Double.compare(getRastojanje(), o.getRastojanje());
    }
}
