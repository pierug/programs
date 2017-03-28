/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package balls;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

import javax.swing.JPanel;
import javax.swing.Timer;

/**
 *
 * @author pieru
 */
public class BallsPanel extends JPanel{
    
    final int size = 20;
    ArrayList<Ball> ballList;
    Timer timer;
    public BallsPanel() {
        ballList=new ArrayList<>();
        this.setBackground(Color.black);
        addMouseListener(new BallsListener());
        timer = new Timer(30,new BallsListener());
        timer.start();
    }
    
    @Override
    public void paintComponent(Graphics graph){
        super.paintComponent(graph);
        for (Ball ball : ballList) {
            graph.fillOval(ball.x, ball.y, size, size);
            graph.setColor(ball.color);
        }
    }
    
    private class BallsListener implements ActionListener, MouseListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            for (Ball ball : ballList) {
                ball.run();
            }
            repaint();
        }

        @Override
        public void mouseClicked(MouseEvent e) {
            ballList.add(new Ball(e.getX()-size/2,e.getY()-size/2));
            repaint();
        }

        @Override
        public void mousePressed(MouseEvent e) {
        }

        @Override
        public void mouseReleased(MouseEvent e) {}

        @Override
        public void mouseEntered(MouseEvent e) {}

        @Override
        public void mouseExited(MouseEvent e) {}
    
    }
    
    class Ball{
        int x;
        int y;
        int speedx;
        int speedy;
        
        Color color;

        public Ball(int x, int y) {
            this.x = x;
            this.y = y;
            this.speedx = (int)(Math.random()*10)-5;
            this.speedy = (int)(Math.random()*10)-5;
            this.color = new Color((int)(Math.random()*255),(int)(Math.random()*255),(int)(Math.random()*255));
        }
        
        public void run(){
            this.x-=this.speedx;
            this.y-=this.speedy;
        }
    }
    
}
