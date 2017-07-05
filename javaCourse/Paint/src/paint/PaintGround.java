/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package paint;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;
import javax.swing.JPanel;

/**
 *
 * @author pieru
 */
public class PaintGround extends JPanel{

    ArrayList<Pen> penList;
    public static boolean pressed = false;
    
    public PaintGround() {
        penList = new ArrayList<>();
        addMouseListener(new PenListener());
        addMouseMotionListener(new PenListener());
    }
    
    public class Pen{
        Color color;
        int x;

        public Pen(Color color, int x, int y, int size) {
            this.color = color;
            this.x = x;
            this.y = y;
            this.size = size;
        }
        int y;
        int size;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g); 
        for (Pen pen : penList) {
            g.setColor(pen.color);
            g.fillOval(pen.x, pen.y, pen.size, pen.size);
        }
    }
    
   
    
    public class PenListener implements MouseListener, MouseMotionListener{     
        
        @Override
        public void mouseClicked(MouseEvent e) {
         
        }

        @Override
        public void mousePressed(MouseEvent e) {
            pressed = true;

        }

        @Override
        public void mouseReleased(MouseEvent e) {
            pressed = false;
        }

        @Override
        public void mouseEntered(MouseEvent e) {
         
        }

        @Override
        public void mouseExited(MouseEvent e) {
         
        }

        @Override
        public void mouseDragged(MouseEvent e) {
            if(pressed){
                penList.add(new Pen(Color.black, e.getX()-5, e.getY()-5, 10));
                repaint(); 
            } 
        }

        @Override
        public void mouseMoved(MouseEvent e) {
            if(pressed){
                penList.add(new Pen(Color.black, e.getX()-5, e.getY()-5, 10));
                repaint(); 
            } 
        }
    
    }
    
    
}
