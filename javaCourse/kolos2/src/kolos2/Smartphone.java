/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolos2;

/**
 *
 * @author pieru
 */
public class Smartphone extends Komputer implements Telefon{
    
    private ConcreteTelefon telefon;

    public Smartphone(String nazwa, String procesor, String dysk, String kartaGraficzna) {
        super(nazwa, Rodzaj.telefon, procesor, dysk, kartaGraficzna);
        telefon = new ConcreteTelefon();
    }

    @Override
    public void dodajKontakt(String nazwa, String telefon) {
        this.telefon.dodajKontakt(nazwa, telefon);
    }

    @Override
    public String wyszukajKontakt(String nazwa) {
        return this.telefon.wyszukajKontakt(nazwa);
    }
    
}
