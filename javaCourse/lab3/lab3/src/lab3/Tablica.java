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
public class Tablica {

    private final int row = 10;
    private final int col = 10;
    private final int minimum = 0;
    private final int maximum = 100;
    private final int element = 121;
    int val;
    
    Kolo[] circles = new Kolo[element];
    
    Tablica() {
        val = (int) (Math.random() * 10) + 10;
    }

    public int[] makeTable() {
        int[] tab = new int[maximum];

        for (int i = 0; i < maximum; i++) {
            tab[i] = (int) (Math.random() * 100);
        }
        return tab;
    }

    public void printTable(int[] tab) {
        int[] avgColumns = new int[col];
        for (int i = 0; i < 10; i++) {
            avgColumns[i] = 0;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                avgColumns[j] += tab[i * row + j];
                if (tab[i * row + j] < 10) {
                    System.out.print("0" + (tab[i * row + j]) + ", ");
                } else {
                    System.out.print((tab[i * row + j]) + ", ");
                }
            }
            System.out.println();
        }
        System.out.println("--------srednia---------");
        for (int i = 0; i < col; i++) {
            if (avgColumns[i] / col < 10) {
                System.out.print("0" + (avgColumns[i] / col) + ", ");
            } else {
                System.out.print((avgColumns[i] / col) + ", ");
            }
        }
        System.out.println();
    }

    public int[][] make2DTable() {

        int[][] tab = new int[val][val];
        for (int i = 0; i < val; i++) {
            for (int j = 0; j < val; j++) {
                if (i == j) {
                    if (((int) (Math.random() * 2) - 1) % 2 == 0) {
                        tab[i][j] = 1;
                    } else {
                        tab[i][j] = -1;
                    }

                } else {
                    tab[i][j] = (int) (Math.random() * 100) - 50;
                }

                System.out.print((tab[i][j]) + ", \t");
            }
            System.out.println();
        }
        return tab;
    }

    public void sumCompare(int[][] tab) {
        int[] sum = {0,0};
        for (int i = 0; i < val; i++) {
            for (int j = 0; j < val; j++) {
                if(j%2==0){//parzyste
                    sum[0] += tab[i][j];
                }
                if(i%2==1){//nieparzyste
                    sum[1] += tab[i][j];
                }
            }
        }
        System.out.println("Parzyste wiersze= "+sum[0]+" Nieparzyste kolumny= "+sum[1]);
    }
    
    private class Kolo{
        int x;
        int y;
        int r;
        Kolo(){
            x = (int) (Math.random() * 200);
            y = (int) (Math.random() * 200);
            r = (int) (Math.random() * 40)+10;
        }
    }
    
    public void makeKoloTab(){
        for (int i = 0; i < element; i++) {
            circles[i] = new Kolo();
            if(i%2==0){
                int tmp = circles[i].x;
                circles[i].x = circles[i].y;
                circles[i].y = tmp;      
            }
            if(circles[i].r > 40){
                circles[i].x += 20;
                circles[i].y -= 10;  
            }
        }
    }
    
    public void printKoloTab(){
        for (int i = 0; i < element; i++) {
            System.out.println("x="+circles[i].x+"; y="+circles[i].y+"; r="+circles[i].r);
        }
    }
}
