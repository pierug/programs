/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolosi;

import java.util.Date;

/**
 *
 * @author pieru
 */
public class Czlowiek {

    public Czlowiek(String imie, String nazwisko, Rodzaj r) {
        this.imie = imie;
        this.nazwisko = nazwisko;
        this.rodzaj = r;
        switch (r){
            case W:{
                this.tablicaWypozyczenia = new PrzedmiotWypozyczenia[20];
                break;
            }
            case S:{
                this.tablicaWypozyczenia = new PrzedmiotWypozyczenia[10];
                break;
            }
            case P:{
                this.tablicaWypozyczenia = new PrzedmiotWypozyczenia[5];
                break;
            }            
        }        
    }

    public String getImie() {
        return imie;
    }

    public void setImie(String imie) {
        this.imie = imie;
    }

    public String getNazwisko() {
        return nazwisko;
    }

    public void setNazwisko(String nazwisko) {
        this.nazwisko = nazwisko;
    }
    
    private String imie;
    private String nazwisko;
    public enum Rodzaj{W,S,P};
    public Rodzaj rodzaj;
    
    public PrzedmiotWypozyczenia[] tablicaWypozyczenia;
    
    public void wypozycz(int index, PrzedmiotWypozyczenia pw){
        tablicaWypozyczenia[index]=pw;
        pw.wypozycz(new Date(),this);
    }
            
}
