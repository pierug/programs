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
public class Ksiazka extends PrzedmiotWypozyczenia{
    
    private int liczbaStron;
    private String format;
    
    public Ksiazka(int index, String tytul, int rokWydania, int liczbaStron, String format) {
        super(index, tytul, rokWydania);
        this.liczbaStron=liczbaStron;
        this.format=format;
    }

    public int getLiczbaStron() {
        return liczbaStron;
    }

    public void setLiczbaStron(int liczbaStron) {
        this.liczbaStron = liczbaStron;
    }

    public String getFormat() {
        return format;
    }

    public void setFormat(String format) {
        this.format = format;
    }
    
}
