package Knjiga;

import Autor.Autor;

public class Knjiga {

    private String naslov;
    private Autor autor;
    private double ocena;

    // Konstruktor
    public Knjiga(String naslov, Autor autor, double ocena){
        this.naslov = naslov;
        this.autor = autor;
        this.ocena = ocena;
    }

    // Get-eri
    public String getNaslov(){
        return naslov;
    }

    public Autor getAutor() {
        return autor;
    }

    public double getOcena() {
        return ocena;
    }

    public String toString() {
        return "Knjiga: " + naslov + "\n" + "Ocena: " + ocena + "\n"
                + "Autor: " + autor.getIme() + " " + autor.getPrezime()
                + "\n" + "Godina rodjenja: " + autor.getGodinaRodjenja();
    }
}
