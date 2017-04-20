/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package labirynt;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 *
 * @author student
 */
public class Menu extends JPanel {

    Plansza plansza;

    // i=0 do góry, i=1 w prawo, i=2 w dół, i=3 w lewo 
    final int UP = 0;
    final int RIGHT = 1;
    final int DOWN = 2;
    final int LEFT = 3;
    int menu;

    public Menu() {
        menu = 2;
        plansza = new Plansza();
        JPanel jpanel = new JPanel(new BorderLayout());

        JPanel upMenu = createMenuPanel();
        JPanel control = createCntrolButtons();

        jpanel.add(upMenu, BorderLayout.NORTH);
        jpanel.add(plansza, BorderLayout.CENTER);
        plansza.setPreferredSize(new Dimension(300, 300));
        jpanel.add(control, BorderLayout.SOUTH);
        this.setLayout(new BorderLayout());
        this.add(jpanel, BorderLayout.CENTER);
        plansza.repaint();
    }

    /*
    public JPanel getMenu(){
        JPanel jpanel = new JPanel(new BorderLayout());
        
        JPanel upMenu = createMenuPanel();
        JPanel control = createCntrolButtons();
        
        jpanel.add(upMenu,BorderLayout.NORTH);
        jpanel.add(plansza,BorderLayout.CENTER);
        plansza.setPreferredSize(new Dimension(300,300));
        jpanel.add(control,BorderLayout.SOUTH);
        
        return jpanel;
    }*/

    public JPanel createMenuPanel() {
        JPanel jpanel = new JPanel(new GridLayout(1, 3));

        JButton newGame = new JButton("Nowa gra");
        JButton aboutGame = new JButton("O grze");
        JButton endGame = new JButton("Koniec gry");

        jpanel.add(newGame);
        jpanel.add(aboutGame);
        jpanel.add(endGame);

        newGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                plansza.setMenu(1); 
                plansza.repaint();
            }
        });
        aboutGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                plansza.setMenu(0); 

                plansza.repaint();
            }
        });
        endGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                
                plansza = new Plansza();
                plansza.setMenu(1); 
                plansza.repaint();
            }
        });

        return jpanel;
    }

    public JPanel createCntrolButtons() {
        JPanel jpanel = new JPanel(new BorderLayout());

        JButton up = new JButton("^");
        JButton down = new JButton("V");
        JButton left = new JButton("<");
        JButton right = new JButton(">");

        jpanel.add(up, BorderLayout.NORTH);
        jpanel.add(down, BorderLayout.SOUTH);
        jpanel.add(left, BorderLayout.WEST);
        jpanel.add(right, BorderLayout.EAST);

        up.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                plansza.PrzesunLudka(UP);
                plansza.repaint();
            }
        });
        down.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                plansza.PrzesunLudka(DOWN);
                plansza.repaint();
            }
        });
        left.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                plansza.PrzesunLudka(LEFT);
                plansza.repaint();
            }
        });
        right.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                System.out.println("RIGHT");
                plansza.PrzesunLudka(RIGHT);
                plansza.repaint();
            }
        });

        return jpanel;
    }
    
    
/*
    @Override
    public void paintComponent(Graphics g) {
        //super.paintComponent(g);
        System.out.println("paintComponent");
        //Graphics2D g2 = (Graphics2D) g;
        //plansza.RysujPlansze(g2);
        
    }*/
    /* public void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;
        plansza.RysujPlansze(g2);
        System.out.println("paintComponent");*/
 /*  switch (menu) {
            case 2:
                plansza = new Plansza();
                menu = 1; //nowa gra
            case 1:
                plansza.RysujPlansze(g2);
                break; //gramy dalej
            case 0:
                g2.drawString("Opis gry ...", 50, 50); //opis gry
        }*/
    //}

    
}
