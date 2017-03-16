package rysownik;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.Timer;

public class KulkowyPanel extends JPanel {

    public static int liczbaKulek = 0;
    
    private ArrayList<Kulki> kulkowaLista;
    private Timer timer;
    private final int DELAY = 33;
    public KulkowyPanel() {
        kulkowaLista = new ArrayList<>();
        setBackground(Color.BLACK);
        addMouseListener(new KulkiListener());
        timer = new Timer(DELAY, new KulkiListener());
        timer.start();
        
    }

    @Override
    public void paintComponent(Graphics graph) {
        super.paintComponent(graph);
        
        for (Kulki kule : kulkowaLista) {
            graph.fillOval(kule.x - kule.size / 2, kule.y - kule.size / 2, kule.size, kule.size);
            graph.setColor(kule.color);
        }
        graph.setColor(new Color(35, 100, 20));
        graph.drawLine(200, 0, 0, 200);
        graph.setColor(new Color(35, 100, 20));
        graph.drawLine(KulkowyPanel.this.getWidth()-200, KulkowyPanel.this.getHeight(), KulkowyPanel.this.getWidth(), KulkowyPanel.this.getHeight()-200);
    }

    private class KulkiListener implements MouseListener, ActionListener {

        @Override
        public void mouseClicked(MouseEvent me) {
            kulkowaLista.add(new Kulki(me.getX(), me.getY(), 30));           
            repaint();
        }

        @Override
        public void mousePressed(MouseEvent me) {

        }

        @Override
        public void mouseReleased(MouseEvent me) {

        }

        @Override
        public void mouseEntered(MouseEvent me) {

        }

        @Override
        public void mouseExited(MouseEvent me) {

        }

        @Override
        public void actionPerformed(ActionEvent ae) {
            for (Kulki kulki : kulkowaLista) {
                kulki.update();
            }
            repaint();
        }

    }

    private class Kulki {
        public int x;
        public int y;
        public int size;
        public int xSpeed;
        public int ySpeed;
        public Color color;
        private final int MAX_SPEED = 20;
        public Kulki(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;
            xSpeed = (int) (Math.random() * MAX_SPEED * 2 - MAX_SPEED);
            ySpeed = (int) (Math.random() * MAX_SPEED * 2 - MAX_SPEED);
            if(xSpeed==0 && ySpeed==0){
                xSpeed++;
                ySpeed--;
            }
            color = new Color((int) (Math.random() *255), (int) (Math.random() *255), (int) (Math.random() *255));
            liczbaKulek++;
        }
        public void update() {
            x += xSpeed;
            y += ySpeed;
            
          /*  for (Kulki kulka : kulkowaLista) {
                if(!kulka.equals(this)){
                    if(kulka.x )
                    
                    if(     (kulka.x+kulka.size >= this.x && 
                            kulka.x<= this.x+this.size) ||
                            (kulka.y+kulka.size >= this.y && 
                            kulka.y<= this.y+this.size)){
                        xSpeed = xSpeed*(-1);
                        ySpeed = ySpeed*(-1);
                    }
                }
            }*/
            
            if(x>=KulkowyPanel.this.getWidth()|| x<=0){
                xSpeed = xSpeed*(-1);
            }
            if(y>=KulkowyPanel.this.getHeight() || y<=0){
                ySpeed = ySpeed*(-1);
            }
            
            if(x <= 200 - y && y <= 200 - x){
                xSpeed = xSpeed*(-1);
                ySpeed = ySpeed*(-1);
            }
            
            if(x <= KulkowyPanel.this.getWidth()-200 + y && y <= KulkowyPanel.this.getHeight()-200 + x ){
                xSpeed = xSpeed*(-1);
                ySpeed = ySpeed*(-1);
            }
            
        }
    }
}
