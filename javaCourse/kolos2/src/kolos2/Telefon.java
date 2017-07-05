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
public interface Telefon {
    public void dodajKontakt(String nazwa, String telefon);
    public String wyszukajKontakt(String nazwa);
}
