/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package balls;

import java.awt.Dimension;
import javax.swing.JFrame;

/**
 *
 * @author pieru
 */
public class Balls {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
        JFrame jframe = new JFrame("OK");
        jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jframe.setContentPane(new BallsPanel());
        jframe.setPreferredSize(new Dimension(700,700));
        jframe.pack();
        jframe.setVisible(true);
    }
    
}
