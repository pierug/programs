package paint;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import javax.imageio.ImageIO;
import javax.swing.JFileChooser;
import javax.swing.JPanel;

public class PaintPanel extends JPanel {

    ArrayList<Point> pointList;

    public static boolean pressed = false;
    private Color penColor;
    private int penSize;
    private boolean isGap = false;
    private int btn = 1;
    private final int LeftBtn = 1;
    private final int RightBtn = 3;

    public Color getPenColor() {
        return penColor;
    }

    public void setPenColor(Color penColor) {
        this.penColor = penColor;
    }

    public int getPenSize() {
        return penSize;
    }

    public void setPenSize(int penSize) {
        this.penSize = penSize;
    }

    public PaintPanel() {
        this.setBackground(Color.WHITE);
        pointList = new ArrayList<>();
        addMouseListener(new PenListener());
        addMouseMotionListener(new PenListener());
        penColor = Color.black;
        penSize = 1;
    }

    public class Point {

        Color color;
        int x;
        int y;
        int size;
        boolean isGap;

        public Point(Color color, int x, int y, int size) {
            this.color = color;
            this.x = x;
            this.y = y;
            this.size = size;
            isGap = false;
        }

        public Point(Color color, int x, int y, int size, boolean g) {
            this.color = color;
            this.x = x;
            this.y = y;
            this.size = size;
            isGap = g;
        }
    }

    public void savaImage() {
        BufferedImage bi = new BufferedImage(this.getWidth(), this.getHeight(), BufferedImage.TYPE_INT_RGB);
        this.paint(bi.getGraphics());

        JFileChooser fileChooser = new JFileChooser();

        fileChooser.setDialogTitle("Specify a file to save");

        int userSelection = fileChooser.showSaveDialog(this);

        if (userSelection == JFileChooser.APPROVE_OPTION) {
            File fileToSave = fileChooser.getSelectedFile();

            try {
                ImageIO.write(bi, "png", fileToSave);

            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        for (int j = 1; j < pointList.size(); j++) {
            if (!pointList.get(j).isGap) {
                g2.setColor(pointList.get(j).color);
                g2.setStroke(new BasicStroke(pointList.get(j).size));
                g2.drawLine(pointList.get(j).x, pointList.get(j).y, pointList.get(j - 1).x, pointList.get(j - 1).y);
            }
        }
    }

    public class PenListener implements MouseListener, MouseMotionListener {

        @Override
        public void mouseClicked(MouseEvent e) {

        }

        @Override
        public void mousePressed(MouseEvent e) {
            pressed = true;
            btn = (e.getButton());
        }

        @Override
        public void mouseReleased(MouseEvent e) {
            pressed = false;
            isGap = true;
        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }

        @Override
        public void mouseDragged(MouseEvent e) {
            if (pressed) {
                if (btn == LeftBtn) {
                    if (isGap) {
                        isGap = false;
                        pointList.add(new Point(getPenColor(), e.getX(), e.getY(), 0, true));
                    } else {
                        pointList.add(new Point(getPenColor(), e.getX(), e.getY(), getPenSize()));
                    }
                }else if(btn == RightBtn){
                    if (isGap) {
                        isGap = false;
                        pointList.add(new Point(getPenColor(), e.getX(), e.getY(), 0, true));
                    } else {
                        pointList.add(new Point(Color.white, e.getX(), e.getY(), getPenSize()));
                    }   
                }
                repaint();
            }
        }

        @Override
        public void mouseMoved(MouseEvent e) {

        }

    }

}
