public class Direktorijum extends ElementFajlSistema {

    private ElementFajlSistema[] sadrzaj;

    public Direktorijum(String ime, String pravaPristupa, ElementFajlSistema[] sadrzaj) {
        super(ime, pravaPristupa);
        this.sadrzaj = sadrzaj;
    }

    public Direktorijum(String ime, String pravaPristupa){
        super(ime, pravaPristupa);
        this.sadrzaj = null;
    }

    @Override
    public void ispisiSadrzaj() {
        if(sadrzaj == null)
            return;
        for (int i = 0; i < sadrzaj.length; i++) {
            if(sadrzaj[i] != null)
                System.out.println(sadrzaj[i].ime + " " + sadrzaj[i].pravaPristupa);
        }
    }

    @Override
    public boolean jeDatoteka() {
        return false;
    }

    @Override
    public boolean jeDirektorijum() {
        return true;
    }
}
