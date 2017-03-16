/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rysownik;

import java.awt.Dimension;
import javax.swing.JFrame;

public class Rysownik extends JFrame{

    public static void main(String[] args) {
       JFrame frame = new JFrame("Rysownik kulek");
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       
       frame.setContentPane(new KulkowyPanel());
       frame.setPreferredSize(new Dimension(600,600));
       frame.pack();
       frame.setVisible(true);
       
    }
    
}
