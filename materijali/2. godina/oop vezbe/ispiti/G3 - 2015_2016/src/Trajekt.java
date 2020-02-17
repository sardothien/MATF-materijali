import java.util.Arrays;

public class Trajekt {

    private Vozilo[] mesta;
    private double maxTezina;
    private double cenaPoJediniciUkupneTezine;

    public Trajekt(int n, double maxTezina, double cenaPoJediniciUkupneTezine) {
        mesta = new Vozilo[n];
        this.maxTezina = maxTezina;
        this.cenaPoJediniciUkupneTezine = cenaPoJediniciUkupneTezine;
    }

    public boolean uvezi(Vozilo a, int i){
        if (a.getTezina() > maxTezina){
            System.out.println("Vozilo " + a + " premasuje dozvoljenu tezinu.");
            return false;
        }
        if(i < 0 || i >= mesta.length){
            System.out.println("Vozilo " + a + " se ne moze parkirati na mesto " + (i+1));
            return false;
        }
        if (mesta[i] != null){
            System.out.println("Mesto " + i + " je zauzeto! Vozilo " + a + " nije parkirano");
            return false;
        }

        mesta[i] = a;
        return true;
    }

    public boolean izvezi(int mesto){
        int i = mesto-1;
        if(i < 0 || i >= mesta.length)
            return false;
        if(mesta[i] == null)
            return false;

        mesta[i] = null;
        return true;
    }

    public double prihod(){
        double prihod = 0;
        for (int i = 0; i < mesta.length; i++) {
            if (mesta[i] != null)
                prihod += mesta[i].getTezina()*cenaPoJediniciUkupneTezine;
        }

        return prihod;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < mesta.length; i++) {
            sb.append((mesta[i] != null) ? mesta[i] : "-- slobodno --").append('\n');
        }
        return sb.toString();
    }
}
