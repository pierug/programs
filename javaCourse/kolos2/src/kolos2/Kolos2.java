/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolos2;

import java.util.Calendar;

/**
 *
 * @author pieru
 */
public class Kolos2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        SklepInternetowy sklepInternetowy = new SklepInternetowy();
        String[] klient = {"Marek Zakrzewski","Aloizy Nader"};
        sklepInternetowy.zamow(klient[0], sklepInternetowy.oferta[2], 22);
        sklepInternetowy.zamow(klient[0], sklepInternetowy.oferta[4], 12);
        sklepInternetowy.zamow(klient[1], sklepInternetowy.oferta[1], 10);
        sklepInternetowy.zamow(klient[1], sklepInternetowy.oferta[3], 7);
        sklepInternetowy.zamow(klient[1], sklepInternetowy.oferta[0], 11);
        sklepInternetowy.zrealizuj(klient[0]);
        sklepInternetowy.zrealizuj(klient[1]);
    }
    
}
