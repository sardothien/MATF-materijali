public class Ovca extends Zivotinja {
    private String[] parole;
    private static int brOvaca = 0;
    private int i = -1;

    public Ovca(String ime, String[] parole) {
        super(ime);
        this.parole = parole;
        brOvaca++;
    }

    public Ovca(Ovca o) {
        this(o.getIme(), o.parole);
    }

    public String[] getParole() {
        return parole;
    }

    public static int getBrOvaca() {
        return brOvaca;
    }

    public void setParole(String[] parole) {
        this.parole = parole;
    }

    public void uglas(){
        System.out.println(getIme() + " ponavlja:");
        String izlaz = toString();
        for (int j = 0; j < brOvaca; j++) {
            System.out.println(izlaz);
        }
    }

    public void naredi(Direktiva d){
        if(d.getIme().equals(getIme())){
            parole = new String[1];
            parole[0] = d.getNaredba();
            i = -1;
        }
    }

    @Override
    public String toString() {
        i++;
        if(i >= parole.length)
            i = 0;
        return "Ovca kaze: '" + parole[i] + "'";
    }
}
