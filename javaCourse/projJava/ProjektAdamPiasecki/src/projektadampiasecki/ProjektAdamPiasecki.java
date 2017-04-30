package projektadampiasecki;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class ProjektAdamPiasecki {

    public static SnakeGraphicPanel snakeGraphicPanel;

    public static void main(String[] args) {
        
//inicjalizacja głównego okna
        JFrame frame = new JFrame("Snake REVENGE");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel mainPanel = new JPanel(new BorderLayout());
        snakeGraphicPanel = new SnakeGraphicPanel();
        mainPanel.requestFocusInWindow();
        mainPanel.add(snakeGraphicPanel, BorderLayout.CENTER);
        frame.addKeyListener(new Keychecker());
        frame.setContentPane(mainPanel);
        frame.setPreferredSize(new Dimension(507, 590));
        frame.pack();
        frame.setResizable(false);
        frame.setVisible(true);
    }
//obsługa przycisków i poruszania się, pamiętając że w przeciwne kierunki nie można zawracać
    static class Keychecker extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {
            switch (e.getKeyCode()) {
                case KeyEvent.VK_UP:
                    if (snakeGraphicPanel.getDirection() != SnakeGraphicPanel.Direction.DOWN) {
                        snakeGraphicPanel.setDirection(SnakeGraphicPanel.Direction.UP);
                    }
                    System.out.println("UP");
                    break;
                case KeyEvent.VK_DOWN:
                    if (snakeGraphicPanel.getDirection() != SnakeGraphicPanel.Direction.UP) {
                        snakeGraphicPanel.setDirection(SnakeGraphicPanel.Direction.DOWN);
                    }
                    System.out.println("DOWN");
                    break;
                case KeyEvent.VK_RIGHT:
                    if (snakeGraphicPanel.getDirection() != SnakeGraphicPanel.Direction.LEFT) {
                        snakeGraphicPanel.setDirection(SnakeGraphicPanel.Direction.RIGHT);
                    }
                    System.out.println("RIGHT");
                    break;
                case KeyEvent.VK_LEFT:
                    if (snakeGraphicPanel.getDirection() != SnakeGraphicPanel.Direction.RIGHT) {
                        snakeGraphicPanel.setDirection(SnakeGraphicPanel.Direction.LEFT);
                    }
                    System.out.println("LEFT");
                    break;
                case KeyEvent.VK_ENTER:
                    snakeGraphicPanel.setNewGame();
                    snakeGraphicPanel.setNewGame(true);
                    snakeGraphicPanel.setIdle(true);
                    snakeGraphicPanel.repaint();
                    System.out.println("VK_ENTER");
                    break;
                case KeyEvent.VK_S:
                    snakeGraphicPanel.setIdle(false);
                    snakeGraphicPanel.setNewGame(true);
                    snakeGraphicPanel.repaint();
                    System.out.println("VK_S");
                    break;
                default:
                    break;
            }
        }
    }
}
