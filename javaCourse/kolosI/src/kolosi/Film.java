/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolosi;

/**
 *
 * @author pieru
 */
public class Film extends PrzedmiotWypozyczenia{

    public int getCzas() {
        return czas;
    }

    public void setCzas(int czas) {
        this.czas = czas;
    }

    public String getRezyser() {
        return rezyser;
    }

    public void setRezyser(String rezyser) {
        this.rezyser = rezyser;
    }

    public String getScenarzysta() {
        return scenarzysta;
    }

    public void setScenarzysta(String scenarzysta) {
        this.scenarzysta = scenarzysta;
    }
    private int czas;
    private String rezyser;
    private String scenarzysta;
    public Film(int index, String tytul, int rokWydania,int czas,String rezyser,String scenarzysta) {
        super(index, tytul, rokWydania);
        this.czas = czas;
        this.rezyser = rezyser;
        this.scenarzysta = scenarzysta;
    }
    
}
