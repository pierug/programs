/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package paint;

import java.awt.Color;
import java.awt.Dimension;
import java.util.Scanner;
import javax.swing.JFrame;

/**
 *
 * @author pieru
 */
public class Paint {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*
        String s = "";
        Scanner scanner = new Scanner(System.in);
        s=scanner.next();
        System.out.println("Dupa"+s);*/
        JFrame jFrame=new JFrame("Paint");
        jFrame.setBackground(Color.WHITE);
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        jFrame.setPreferredSize(new Dimension(800, 800));
        jFrame.setContentPane(new PaintGround());
        jFrame.pack();
        jFrame.setVisible(true);
    }
    
}
