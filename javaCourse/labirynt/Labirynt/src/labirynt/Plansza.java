/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package labirynt;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Toolkit;
import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 *
 * @author student
 */
public class Plansza extends JPanel {

    private int w = 10; //wysokość planszy
    private int h = 10; //szerokość planszy
    private int[] plansza = new int[100]; //tablica pomocnicza obrazu planszy
    private int PozycjaGracza = 0; //początkowa pozycja gracza
    private int StaraPozycjaGracza = 0; //poprzednia pozycja gracza
    private int Meta = 90; //pozycja mety 
    private int menu = 1;
    public boolean win = false;

    public void setMenu(int menu) {
        this.menu = menu;
    }
    private int[] Kolumny = {3, 5, 11, 12, 13, 18, 23, 24, 25, 28, 38,
        48, 93}; //rozmieszczenie kolumn labiryntu
//dodaj więcej kolumn
    private String[] nazwy = {"podloga.jpg", //kod 0
        "kolumna.jpg", //kod 1
        "miejsce.jpg", //kod 2
        "gracz.jpg", //kod 3
        "graczmc.jpg" //kod 4
}; //tablica z nazwami obrazków
    private Image obrazy[] = new Image[nazwy.length]; //tablica z obrazami

    public Plansza() //konstruktor klasy Plansza
    {
        for (int i = 0; i < Kolumny.length; i++) {
            Kolumny[i] = (int) (Math.random() * 99) + 1;
        }
        Meta = (int) (Math.random() * 99) + 1;
        for (int i = 0; i < nazwy.length; i++) {
            obrazy[i] = Toolkit.getDefaultToolkit().getImage(nazwy[i]);
        }
        UstawPlansze();
    }
    public void nowySet(){
        PozycjaGracza = 0; //początkowa pozycja gracza
        StaraPozycjaGracza = 0; //poprzednia pozycja gracza
        for (int i = 0; i < Kolumny.length; i++) {
            Kolumny[i] = (int) (Math.random() * 99) + 1;
        }
        Meta = (int) (Math.random() * 99) + 1;
        UstawPlansze();
    }
    private void UstawPlansze() //ustaw pozycje obrazków na planszy
    {
        for (int i = 0; i < (w * h); i++) // wypełnij tablice zerami
        {
            plansza[i] = 0; // 0 - kod pustego miejsca (podloga)
        }
        plansza[Meta] = 2; // 2 - kod mety
        plansza[PozycjaGracza] = 3; // 3- kod pozycji gracza
        for (int i = 0; i < Kolumny.length; i++) { //ustaw kolumny
            //ustaw kolumny na planszy, 1 - kod kolumny
            plansza[Kolumny[i]] = 1;
        }
    }

    private void ZmienPlansze() //zmianie ulega tylko pozycja gracza
    {
//jeśli gracz wchodzi na kolumnę - cofamy gracza do poprzedniej pozycji
//jeśli pozycja gracza różni się od starej pozycji gracza – na starej
//pozycji rysujemy podłogę
//jeśli pozycja gracza pokrywa się z metą – w miejscu mety rysujemy
//obrazek z graczem na mecie
        if (plansza[PozycjaGracza] == 2) {
            win = true;
            plansza[PozycjaGracza] = 4;
            plansza[StaraPozycjaGracza] = 0;
        } else if (plansza[PozycjaGracza] == 1) {
            PozycjaGracza = StaraPozycjaGracza;
        } else if (plansza[PozycjaGracza] == 0) {
            plansza[PozycjaGracza] = 3;
            plansza[StaraPozycjaGracza] = 0;
        }
    }

    public void RysujPlansze(Graphics2D g) {
        if (!win) {
            ZmienPlansze();
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    g.drawImage(obrazy[plansza[i + w * j]], i * 30, j * 30, this);
                }
            }
        }
    }

    public void PrzesunLudka(int i) { // i=0 do góry, i=1 w prawo, i=2 w dół, i=3 w lewo
        switch (i) {
            case 0:
                StaraPozycjaGracza = PozycjaGracza;
                System.out.println("StaraPozycjaGracza: " + PozycjaGracza);
                if (PozycjaGracza - 10 >= 0) //sprawdz czy można
                {
                    PozycjaGracza -= 10;
                }
                break;
            case 1: //uzupełnić
                StaraPozycjaGracza = PozycjaGracza;
                System.out.println("StaraPozycjaGracza: " + PozycjaGracza);
                if (PozycjaGracza + 1 < 100) //sprawdz czy można
                {
                    PozycjaGracza += 1;
                }
                break;
            case 2:
                StaraPozycjaGracza = PozycjaGracza;
                System.out.println("StaraPozycjaGracza: " + PozycjaGracza);
                if (PozycjaGracza + 10 < 100) //sprawdz czy można
                {
                    PozycjaGracza += 10;
                }
                break;
            case 3: //uzupełnić
                StaraPozycjaGracza = PozycjaGracza;
                System.out.println("StaraPozycjaGracza: " + PozycjaGracza);
                if (PozycjaGracza - 1 >= 0) //sprawdz czy można
                {
                    PozycjaGracza -= 1;
                }
                break;
        }
    }

    @Override
    protected void paintComponent(Graphics grphcs) {
        super.paintComponent(grphcs);
        System.out.println("paintComponent");
        Graphics2D g2 = (Graphics2D) grphcs;
        switch (menu) {
            case 1:
                RysujPlansze(g2);
                break; //gramy dalej
            case 0:
                g2.drawString("Kretodyle atakują Manhatan,", 50, 50); //opis gry
                g2.drawString("sytuacje może uratować jedynie", 50, 70); //opis gry
                g2.drawString("koleś chodzący po kafelkach!!!", 50, 90); //opis gry
        }
        if (win) {
            g2.drawString("Koniec Gry, zagraj jeszcze raz", 50, 50); //opis gry
        }

    }

}
