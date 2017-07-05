/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1powtorka;

/**
 *
 * @author pieru
 */
public class Lab1Powtorka {

    public static void makeTriangle(int n){
        for(int i=0;i<n;i++){
            for (int j = 0; j <(n*2-i)-1; j++) {
                if(i==0){
                    System.out.print("*");
                }else if(j==i){
                    System.out.print("*");
                }else if(j==(n*2-i)-2){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
            }
            System.out.println("");
        }
    }
    public static void makeTriangle2(int n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= (n+i); j++) {
                if (j<n-i) {
                    System.out.print(" ");
                }else{
                    System.out.print("*");
                }
            }
            System.out.println("");
        }
    }
    public static void makeTriangle3(int n){

        for (int i = 0; i < n*2-1; i++) {
            for (int j = 0; j < n; j++) {
                if(n>i){
                    if(j<=i){
                        System.out.print("*");
                    }else{
                        System.out.print(" ");    
                    }
                }else{
                    if(j<n*2-1-i){
                        System.out.print("*");
                    }else{
                        System.out.print(" ");    
                    }
                }
            }
            System.out.println("");
        }
    }   
    public static void makeTriangle4(int n){

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n+i; j++) {
                if(i==n-1){
                    System.out.print("*");
                }else if(j==n-i-1){
                    System.out.print("*");
                }else if(n+i-1==j){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
                
            }
            System.out.println("");
        }
    }   
    public static void main(String[] args) {
        makeTriangle4(3);

    }
    
}
