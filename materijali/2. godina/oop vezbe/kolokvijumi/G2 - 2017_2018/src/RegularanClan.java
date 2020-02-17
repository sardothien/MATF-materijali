public class RegularanClan extends Clan {

    private Film iznajmljenFilm;

    public RegularanClan(String imeOsobe, String omiljeniZanr) {
        super(imeOsobe, omiljeniZanr);
        this.iznajmljenFilm = null;
    }

    public Film getIznajmljenFilm() {
        return iznajmljenFilm;
    }

    public void iznajmiReg(Film f){
        if(!f.isIznajmljen() && iznajmljenFilm == null) {
            f.setIznajmljen(true);
            iznajmljenFilm = f;
            System.out.println(getImeOsobe() + " iznajmljuje " + f.getNaziv() + ".");
        }
        else if(f.isIznajmljen()) {
            System.out.println(getImeOsobe() + ", film " + f.getNaziv() + " je" +
                    "trenutno iznajmljen.");
        }
        else{
            System.out.println(getImeOsobe() + ", ne mozete iznajmiti vise filmova istovremeno!" +
                    " Trenutno iznajmljeni film: " + iznajmljenFilm.getNaziv() + ".");
        }
    }

    public void vratiReg(){
        iznajmljenFilm.setIznajmljen(false);
        System.out.println(getImeOsobe() + " vraca " + iznajmljenFilm.getNaziv() + ".");
        iznajmljenFilm = null;
    }

    @Override
    public String toString() {
        if(iznajmljenFilm != null)
            return super.toString() + "; Trenutno iznajmljeno: " +
                    iznajmljenFilm.getNaziv() + "; Clanarina: 1000.0";
        else
            return super.toString() + "; Clanarina: 1000.0";
    }
}
