/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1;

/**
 *
 * @author pieru
 */
public class Lab1 {

    /**
     * @param args the command line arguments
     */
    
    public static void printTriangleA(int n) {
        System.out.println("a)");
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= x; y++) {
                System.out.print(x);
            }
            System.out.println();
        }
    }
    
    public static void printTriangleB(int n) {
        System.out.println("b)");
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= x; y++) {
                System.out.print(y);
            }
            System.out.println();
        }
    }
    
    public static void printSquareC(int n) {
        System.out.println("c)");
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    
    
    public static void printTriangleD(int n) {
        System.out.println("d)");
        for (int x = 0; x < n; x++) {
            for (int y = 0; y <= x; y++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    
    
    public static void printTriangleE(int n) {
        System.out.println("e)");
        for (int x = 0; x<n ; x++) {
            for (int y = 0; y <= n+x; y++) {
                if (y<n-x) {
                    System.out.print(" ");
                }else{
                    System.out.print("*");   
                }
            }
            System.out.println();
        }
    }
    
    public static void printTriangleF(int n) {
        System.out.println("f)");
        for (int x = n; x>0 ; x--) {
            for (int y = 0; y < n+x-1; y++) {
                if(n==x){
                    System.out.print("*");
                }else if(n-x==y){
                    System.out.print("*");
                }else if(y==n+x-2){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        int i,j;
        int k=10;
        double x=1.256664;
        char znak='z';
        double y;
        i=0;
        j=333;
        y=0.001;
        System.out.println("Witamy w Javie!\n");
        System.out.println("Java - start..");
        System.out.println("j="+j+"; x="+x);
        System.out.printf("j=%5d, x=%5.5f \n",j,x);
        printTriangleA(7);
        printTriangleB(7);
        printSquareC(4);
        printTriangleD(4);
        printTriangleE(5);
        printTriangleF(10);
    }
    
}
