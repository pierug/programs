/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class Szyfr {
    
    public String szyfruj(){
        Scanner odczyt = new Scanner(System.in);
        String wiadomosc = odczyt.nextLine();
        System.out.println("Wiadomosć do zaszyfrowania o 3: "+wiadomosc);
        String zaszyfrowana = new String("");
        for (int i = 0; i < wiadomosc.length(); i++) {
            if((wiadomosc.charAt(i)>='A')&&(wiadomosc.charAt(i)<='W')){
                zaszyfrowana += (char)( wiadomosc.charAt(i) + 3);        
            }else if((wiadomosc.charAt(i)>='X')&&(wiadomosc.charAt(i)<='Z')){
                zaszyfrowana += (char)( wiadomosc.charAt(i)-23);
            }else if((wiadomosc.charAt(i)>='a')&&(wiadomosc.charAt(i)<='w')){
                zaszyfrowana += (char)( wiadomosc.charAt(i) + 3); 
            }else if((wiadomosc.charAt(i)>='x')&&(wiadomosc.charAt(i)<='z')){
                zaszyfrowana += (char)( wiadomosc.charAt(i)-23);
            }else if((wiadomosc.charAt(i)>='0')&&(wiadomosc.charAt(i)<='6')){
                zaszyfrowana += (char)( wiadomosc.charAt(i) + 3); 
            }else if((wiadomosc.charAt(i)>='7')&&(wiadomosc.charAt(i)<='9')){
                zaszyfrowana += (char)( wiadomosc.charAt(i)-7 );
            }else{
                 zaszyfrowana += wiadomosc.charAt(i);
            }
        }
        return zaszyfrowana;
    }
}
