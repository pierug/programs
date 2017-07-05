/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;

/**
 *
 * @author student
 */
public class Lab3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Tablica tablica = new Tablica();
        int[] tab = new int[100];
        
        tab = tablica.makeTable();
        
        tablica.printTable(tab);
        int[][] tab2D = tablica.make2DTable();
        tablica.sumCompare(tab2D);
        tablica.makeKoloTab();
        tablica.printKoloTab();
    }
    
}
