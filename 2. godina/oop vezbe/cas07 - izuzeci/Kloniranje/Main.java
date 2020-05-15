package Kloniranje;

public class Main {
    /* Kloniranje:
     *    1) implementirati Cloneable interfejs
     *    2) definisati clone() metod koji handle-uje ili baca CloneNotSupportedException
     *    3) pozvati clone() metod natklase*/

    public static void main(String[] args) {
        try {
            Pas mojLjubimac = new Pas("Maza", "mesanac");
            Pas tvojLjubimac = (Pas) mojLjubimac.clone();

            tvojLjubimac.setIme("Lunja");
            tvojLjubimac.getBuva().setIme("buvica");

            System.out.println("Detalji o tvom psu: " + tvojLjubimac);
            System.out.println("Detalji o mom psu: " + mojLjubimac);
            System.out.println("----------------------------------");

            Buva klonBuva = (Buva) tvojLjubimac.getBuva().clone();
            mojLjubimac.setBuva(klonBuva);
            mojLjubimac.getBuva().setIme("klonirana buva");

            System.out.println("Posle kloniranja buve:");
            System.out.println("Detalji o tvom psu: " + tvojLjubimac);
            System.out.println("Detalji o mom psu: " + mojLjubimac);
        }
        catch (CloneNotSupportedException e){
            e.printStackTrace(System.err);
        }
        finally {

        }
    }
}
