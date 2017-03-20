package rysownik;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
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
        addMouseWheelListener(new KulkiListener());
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
        int[] xPoints1 = {0, 0, 200};
        int[] yPoints1 = {200, 0, 0};

        graph.fillPolygon(xPoints1, yPoints1, 3);
        
        int[] xPoints2 = {KulkowyPanel.this.getWidth() - 200, KulkowyPanel.this.getWidth(), KulkowyPanel.this.getWidth()};
        int[] yPoints2 = {KulkowyPanel.this.getHeight(), KulkowyPanel.this.getHeight(), KulkowyPanel.this.getHeight() - 200};
        graph.fillPolygon(xPoints2, yPoints2, 3);
        
        graph.setColor(new Color(0, 0, 0));
        Font f = new Font("Dialog", Font.PLAIN, 20);
        graph.setFont(f);
        String string = Integer.toString(liczbaKulek);
        graph.drawString("Liczba kulek: "+string, 25, 25);
    }

    private class KulkiListener implements MouseListener, ActionListener, MouseWheelListener {

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

        @Override
        public void mouseWheelMoved(MouseWheelEvent e) {
            int rotation = e.getWheelRotation();
            System.out.println("DUPA");
            for (Kulki kulki : kulkowaLista) {
                if(kulki.size-rotation>0){
                    kulki.size=kulki.size+rotation;
                }
            }
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
            if (xSpeed == 0 && ySpeed == 0) {
                xSpeed++;
                ySpeed--;
            }
            color = new Color((int) (Math.random() * 255), (int) (Math.random() * 255), (int) (Math.random() * 255));
            liczbaKulek++;
        }

        public void update() {
            x += xSpeed;
            y += ySpeed;

            for (Kulki kulka : kulkowaLista) {
                if (!kulka.equals(this)) {
                    if ((this.y + this.size >= kulka.y) && (this.y <= kulka.size + kulka.y)
                            && (this.x + this.size >= kulka.x) && (this.x <= kulka.size + kulka.x)) {
                        xSpeed = xSpeed * (-1);
                        ySpeed = ySpeed * (-1);
                    }
                }
            }

            if (x >= KulkowyPanel.this.getWidth() || x <= 0) {
                xSpeed = xSpeed * (-1);
            }
            if (y >= KulkowyPanel.this.getHeight() || y <= 0) {
                ySpeed = ySpeed * (-1);
            }

            if (x <= 200 - y && y <= 200 - x) {
                xSpeed = xSpeed * (-1);
                ySpeed = ySpeed * (-1);
            }

            if (x >= KulkowyPanel.this.getWidth() - 200 + KulkowyPanel.this.getHeight() - y && y >= KulkowyPanel.this.getHeight() - 200 + KulkowyPanel.this.getWidth() - x) {
                xSpeed = xSpeed * (-1);
                ySpeed = ySpeed * (-1);
            }

        }
    }
}
