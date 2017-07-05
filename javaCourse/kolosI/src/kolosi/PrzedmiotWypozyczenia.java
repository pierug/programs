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
public class PrzedmiotWypozyczenia {
    private int index;
    private String tytul;
    private int rokWydania;
    private Date dataWypozyczenia;
    public boolean statusWypozyczenia;
    private Czlowiek wypozyczajacy;

    public Czlowiek getWypozyczajacy() {
        return wypozyczajacy;
    }

    public void setWypozyczajacy(Czlowiek wypozyczajacy) {
        this.wypozyczajacy = wypozyczajacy;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public String getTytul() {
        return tytul;
    }

    public void setTytul(String tytul) {
        this.tytul = tytul;
    }

    public int getRokWydania() {
        return rokWydania;
    }

    public void setRokWydania(int rokWydania) {
        this.rokWydania = rokWydania;
    }

    public Date getDataWypozyczenia() {
        return dataWypozyczenia;
    }

    public void setDataWypozyczenia(Date dataWypozyczenia) {
        this.dataWypozyczenia = dataWypozyczenia;
    }

    public PrzedmiotWypozyczenia(int index, String tytul, int rokWydania) {
        this.index = index;
        this.tytul = tytul;
        this.rokWydania = rokWydania;
    }
    
    
    public void wypozycz(Date dataWypozyczenia, Czlowiek czlowiek ){
        this.dataWypozyczenia = dataWypozyczenia;
        this.wypozyczajacy = czlowiek;
        this.statusWypozyczenia = true;
    }
    
    public void zwroc(){
        this.dataWypozyczenia = null;
        this.statusWypozyczenia = false;
    }
}
