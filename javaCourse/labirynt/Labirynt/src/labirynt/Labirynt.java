/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package labirynt;

import java.awt.Dimension;
import javax.swing.JFrame;

/**
 *
 * @author student
 */
public class Labirynt {

    public static void main(String[] args) {
        JFrame jFrame = new JFrame("Labirynt");
        
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        jFrame.setPreferredSize(new Dimension(400, 600));      
  
        jFrame.setContentPane(new Menu());
        
        jFrame.pack();
        jFrame.setVisible(true);
                
    }
    
}
