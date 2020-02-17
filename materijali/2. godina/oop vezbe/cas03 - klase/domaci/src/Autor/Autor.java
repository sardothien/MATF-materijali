package Autor;

import java.util.Calendar;

public class Autor {
    private String ime;
    private String prezime;
    private int godinaRodjenja;

    // Konstruktor
    public Autor(String ime, String prezime, int godinaRodjenja) {
        this.ime = ime;
        this.prezime = prezime;
        this.godinaRodjenja = godinaRodjenja;
    }

    // Get-eri
    public String getIme() {
        return ime;
    }

    public String getPrezime(){
        return prezime;
    }

    public String getGodinaRodjenja() {
        return Integer.toString(godinaRodjenja);
    }

    public int getGodine() {
        return Calendar.getInstance().get(Calendar.YEAR) - godinaRodjenja;
    }

    // Fja
    public String toString(){
        return "Autor: " + ime + " " + prezime + "\n" + "Godina rodjenja: " + godinaRodjenja;
    }
}
