package projektadampiasecki;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.Timer;

public class SnakeGraphicPanel extends JPanel {

    enum Direction {
        UP, DOWN, LEFT, RIGHT
    };
    private Direction direction;
    private final int xPanelSize = 500;
    private final int yPanelSize = 500;

    private ArrayList<Point> snake;
    private ArrayList<Point> obstacles;
    private Point apple;
    private int score;
    private int obstaclesNumber;
    private Timer timer;
    public final int INTERWAL = 30;
    public final int INITIAL_SEGMENT_NUMBER = 5;
    public final int CENTER_X = 240;
    public final int CENTER_Y = 240;
    public final int STEP = 20;
    public int tickInterwal;
    private final int INITIAL_SPEED = 7;
    private boolean newGame;
    private boolean idle;

    public void setNewGame(boolean newGame) {
        this.newGame = newGame;
    }

    public void setIdle(boolean idle) {
        this.idle = idle;
    }

    public boolean isNewGame() {
        return newGame;
    }

    public boolean isIdle() {
        return idle;
    }

    public Direction getDirection() {
        return direction;
    }

    public void setDirection(Direction direction) {
        this.direction = direction;
    }

// wygenerowanie jabłka, daje punkty graczowi
// generuje na miejscu losowym, gdzie nie ma gracza i przeszkody
    public void generateApple() {
        int randomPosX = 0;
        int randomPosY = 0;
        while (randomPosX == 0) {
            randomPosX = (int) (Math.random() * (xPanelSize / 20)) * 20;
            for (Point s : snake) {
                if (s.x == randomPosX) {
                    randomPosX = 0;
                    break;
                }
            }
            for (Point p : obstacles) {
                if (p.x == randomPosX) {
                    randomPosX = 0;
                    break;
                }
            }
        }
        while (randomPosY == 0) {
            randomPosY = (int) (Math.random() * (yPanelSize / 20)) * 20;
            for (Point s : snake) {
                if (s.y == randomPosY) {
                    randomPosY = 0;
                    break;
                }
            }
            for (Point p : obstacles) {
                if (p.y == randomPosY) {
                    randomPosY = 0;
                    break;
                }
            }
        }
        apple = new Point(randomPosX, randomPosY);
    }
//generowanie listy przeszkód w zależności od punktów, max 10

    private void generateObstacles() {
        obstacles.clear();
        if ((score % 5) == 4) {
            if (obstaclesNumber < 10) {
                obstaclesNumber++;
            }
        }
        for (int i = 0; i < obstaclesNumber; i++) {
            generateObstacle();
        }
    }
// wygenerowanie przeszkody, jak wąż w niego wjedzie to koniec gry
// generuje na miejscu losowym, gdzie nie ma gracza i innej przeszkody

    private void generateObstacle() {
        int randomPosX = 0;
        int randomPosY = 0;
        while (randomPosX == 0) {
            randomPosX = (int) (Math.random() * (xPanelSize / 20)) * 20;
            for (Point s : snake) {
                if (s.x == randomPosX) {
                    randomPosX = 0;
                    break;
                }
            }
            for (Point p : obstacles) {
                if (p.x == randomPosX) {
                    randomPosX = 0;
                    break;
                }
            }
        }
        while (randomPosY == 0) {
            randomPosY = (int) (Math.random() * (yPanelSize / 20)) * 20;
            for (Point s : snake) {
                if (s.y == randomPosY) {
                    randomPosY = 0;
                    break;
                }
            }
            for (Point p : obstacles) {
                if (p.y == randomPosY) {
                    randomPosY = 0;
                    break;
                }
            }
        }
        obstacles.add(new Point(randomPosX, randomPosY));
    }
//konstruktor

    public SnakeGraphicPanel() {
        obstacles = new ArrayList<>();
        snake = new ArrayList<>();
        apple = new Point();
        direction = Direction.DOWN;
        idle = true;
        newGame = false;
        timer = new Timer(INTERWAL, new SnakeListener());
        timer.start();
        setNewGame();
        this.setPreferredSize(new Dimension(xPanelSize, yPanelSize));
        this.setBackground(Color.BLACK);
        this.repaint();
    }
//metoda inicjalizująca grę

    public boolean setNewGame() {
        snake.clear();
        obstacles.clear();
        direction = Direction.DOWN;
        newGame = false;
        idle = true;
        tickInterwal = INITIAL_SPEED;
        apple = new Point();
        obstaclesNumber = 2;
        generateApple();
        generateObstacles();
        score = 0;
        for (int i = 0; i < INITIAL_SEGMENT_NUMBER; i++) {
            snake.add(new Point(CENTER_X, i * STEP + CENTER_Y));
        }
        repaint();
        return true;
    }
//metoda sprawdzająca czy wystąpiła kolizja z przeszkodami i ścianą

    private boolean isColision() {
        int frontX = snake.get(snake.size() - 1).x;
        int frontY = snake.get(snake.size() - 1).y;

        if (frontX < 0) {
            return true;
        }
        if (frontX >= xPanelSize) {
            return true;
        }
        if (frontY < 0) {
            return true;
        }
        if (frontY >= yPanelSize) {
            return true;
        }

        for (int i = 0; i < snake.size() - 1; i++) {
            if (frontY == snake.get(i).y && frontX == snake.get(i).x) {
                return true;
            }
        }

        for (Point p : obstacles) {
            if (p.x == frontX && p.y == frontY) {
                return true;
            }
        }

        return false;
    }
// metoda kończąca grę

    private void endGame() {
        idle = true;

        int dialogButton = JOptionPane.YES_NO_OPTION;
        int dialogResult = JOptionPane.showConfirmDialog(null, "Zacząć od nowa?", "Przegrałeś!!!", dialogButton);
        if (dialogResult == JOptionPane.YES_OPTION) {
            setNewGame();
        } else {
            System.exit(0);
        }
    }
//metoda sprawdzająca czy zjedzone zostało jabłko

    private boolean isGetApple() {
        int frontX = snake.get(snake.size() - 1).x;
        int frontY = snake.get(snake.size() - 1).y;

        if (frontX == apple.x && frontY == apple.y) {
            return true;
        }

        return false;
    }
// metoda odpoiwdająca za przemieszczanie węża

    public void moveSnake() {

        int frontX = snake.get(snake.size() - 1).x;
        int frontY = snake.get(snake.size() - 1).y;

        if (null != direction) {
            switch (direction) {
                case UP:
                    snake.add(new Point(frontX, frontY - STEP));
                    break;
                case DOWN:
                    snake.add(new Point(frontX, frontY + STEP));
                    break;
                case LEFT:
                    snake.add(new Point(frontX - STEP, frontY));
                    break;
                case RIGHT:
                    snake.add(new Point(frontX + STEP, frontY));
                    break;
                default:
                    break;
            }
        }
//jeżeli zostało zjedzone jabłko to nie usuwamy segmentu zerowego węża, i obliczamy na postawie punktów
//interwał czasowy (zwiększam szybkość)
//jak nie zostało zjedzone jabłko to usuwam zerowy segment, czyli wąż nie rośnie
        if (isGetApple()) {
            generateApple();
            score++;
            if ((score % 5) == 4) {
                tickInterwal--;
            }
            if (tickInterwal <= 1) {
                tickInterwal = 1;
            }
            generateObstacles();
        } else {
            snake.remove(0);
        }
//sprawdzam kolizję 
        if (isColision()) {
            System.out.println("Colision");
            endGame();
        }
    }
//rysowanie

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.white);
        Graphics2D graphics2D = (Graphics2D) g;
        g.drawRect(0, 0, xPanelSize, yPanelSize);
//proste menu, w zależności czy gra jest w spoczynku-idle, czy zaotała wybrana nowa gra
        if (idle) {
            if (newGame) {
                g.drawString("Wciśnij S - START", STEP, STEP);
                g.drawString("Gra się strzałkami", STEP, STEP * 3);
                g.drawString("ENTER - NOWA GRA", STEP, STEP * 6);
            } else {
                g.drawString("ENTER - NOWA GRA", STEP, STEP);
            }
        } else {
// rysowanie elementów, punktacji i prędkości
            moveSnake();
            drawApple(apple.x, apple.y, STEP, STEP, graphics2D);
            for (Point s : snake) {
                drawSegment(s.x, s.y, STEP, STEP, graphics2D);
            }
            for (Point p : obstacles) {
                drawObstacle(p.x, p.y, STEP, STEP, graphics2D);
            }
            g.setColor(Color.white);
            g.drawString("Punkty: " + score, STEP, STEP + yPanelSize);
            String speedString = "";
            for (int i = 0; i < INITIAL_SPEED - tickInterwal; i++) {
                speedString += ">";
            }
            g.drawString("Prędkosć: " + speedString, STEP, STEP * 2 + yPanelSize);
        }
    }

    private void drawSegment(int x, int y, int sizeX, int sizeY, Graphics2D graphics2D) {
        graphics2D.setColor(Color.GREEN);
        graphics2D.fillRect(x, y, sizeX, sizeY);
        graphics2D.setColor(Color.BLACK);
        graphics2D.drawRect(x, y, sizeX, sizeY);
    }

    private void drawApple(int x, int y, int sizeX, int sizeY, Graphics2D graphics2D) {
        graphics2D.setColor(Color.RED);
        graphics2D.fillOval(x, y, sizeX, sizeY);
        graphics2D.setColor(Color.BLACK);
        graphics2D.drawOval(x, y, sizeX, sizeY);
    }

    private void drawObstacle(int x, int y, int sizeX, int sizeY, Graphics2D graphics2D) {
        graphics2D.setColor(Color.WHITE);
        graphics2D.fillRect(x, y, sizeX, sizeY);
        graphics2D.setColor(Color.BLACK);
        graphics2D.drawRect(x, y, sizeX, sizeY);
    }
// event wykonywany co interwał timera

    private class SnakeListener implements ActionListener {

        int tick = 0;
// rysowanie odbywa się tylko co określony za pomocą tickInterwal obieg timera
// to pozwala zmieniać prędkosć gry

        @Override
        public void actionPerformed(ActionEvent e) {
            if (tick >= tickInterwal) {
                tick = 0;
                if (!newGame) {
                    idle = true;
                }
                repaint();
            } else {
                tick++;
            }
        }
    }
}
