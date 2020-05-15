public class KodiranaPoruka {

    private String mBitovi;
    private String cBitovi;

    public KodiranaPoruka(String mBitovi, String cBitovi) {
        this.mBitovi = mBitovi;
        this.cBitovi = cBitovi;
    }

    public String getmBitovi() {
        return mBitovi;
    }

    public String getcBitovi() {
        return cBitovi;
    }

    @Override
    public String toString() {
        return mBitovi + " : " + cBitovi;
    }
}
