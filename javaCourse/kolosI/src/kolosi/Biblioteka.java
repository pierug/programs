/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolosi;

import java.util.ArrayList;

public class Biblioteka {
    private final int liczbaLudzi=2;
    
    public ArrayList<PrzedmiotWypozyczenia> kolekcja;
    
    public Czlowiek[] ludzie;

    public Biblioteka() {
        kolekcja =new ArrayList<>();
        ludzie = new Czlowiek[liczbaLudzi];
        kolekcja.add(new Ksiazka(0, "Ten Obcy", 1981,220,"A5"));
        kolekcja.add(new Ksiazka(1, "Obcy", 1981,220,"A4"));
        kolekcja.add(new Ksiazka(2, "Ten", 1981,220,"A5"));
        kolekcja.add(new Ksiazka(3, "Cesarz", 1983,23,"A4"));
        kolekcja.add(new Ksiazka(4, "Ten Obcy", 1981,234,"A5"));
        kolekcja.add(new Ksiazka(5, "XXX", 1981,124,"A5"));
        kolekcja.add(new Ksiazka(6, "Ten Obcy", 1983,34,"A5"));
        kolekcja.add(new Ksiazka(7, "XXX", 1981,122,"A5"));
        kolekcja.add(new Ksiazka(9, "XXX", 1985,241,"A4"));
        kolekcja.add(new Ksiazka(10, "Ten Obcy", 1981,220,"A5"));
        kolekcja.add(new Ksiazka(11, "Cesarz", 1986,220,"A5"));
        kolekcja.add(new Ksiazka(12, "Ten Obcy", 1977,220,"A5"));
        kolekcja.add(new Ksiazka(13, "XXX", 1981,220,"A4"));
        kolekcja.add(new Ksiazka(14, "Ten Obcy", 1987,220,"A4"));
        kolekcja.add(new Ksiazka(15, "Cesarz", 1988,220,"A4"));
        kolekcja.add(new Ksiazka(16, "Ten Obcy", 1977,220,"A5"));
        
        kolekcja.add(new Film(17, "Cycate opowieści", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(18, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(19, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(20, "Lachociągi", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(21, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(22, "Ten Obcy", 1981,180,"Adam Deniel", "Adam Piasecki"));
        kolekcja.add(new Film(23, "Lachociągi", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(24, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(25, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(26, "Deep Throat", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(27, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Daniel"));
        kolekcja.add(new Film(28, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(29, "Deep Throat", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(30, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        kolekcja.add(new Film(31, "Ten Obcy", 1981,180,"Adam Pisecki", "Adam Piasecki"));
        
        ludzie[0] = new Czlowiek("Sylwia", "Podkościelna",Czlowiek.Rodzaj.S);
        ludzie[1] = new Czlowiek("Doktor", "Ząbek",Czlowiek.Rodzaj.W);
    }

    public void wyswietlStan(){
        System.out.println("Stan biblioteki!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        System.out.println("Do wypozyczenia:+++++++++++++++++++++++++++");
        for (PrzedmiotWypozyczenia p : kolekcja) {
            if(p.statusWypozyczenia == false){
                System.out.println("Index :"+p.getIndex()+", "+p.getTytul()+", "+p.getRokWydania());
            }
        }
        
        System.out.println("Wypozyczone:-------------------------------");
        for (PrzedmiotWypozyczenia p : kolekcja) {
            if(p.statusWypozyczenia == true){
                System.out.println("Index :"+p.getIndex()+", "+p.getTytul()+", "+p.getRokWydania()+", data wypozyczenia: "+p.getDataWypozyczenia()+", Wypozyczyl :"+p.getWypozyczajacy().getNazwisko()+" "+p.getWypozyczajacy().getImie());
            }
        }
    }
    public void wypozycz(){
        for (int i = 0; i < liczbaLudzi; i++) {
            Czlowiek.Rodzaj r = ludzie[i].rodzaj;
            int j=0;
            switch(r){
                case P:{
                    j=5;
                    break;
                }
                case W:{
                    j=20;
                    break;
                }
                case S:{
                    j = 10;
                    break;
                }
            }
            int wypozyczone=0;
            for (int k = 0; k < j; k++) {
                int rand = (int)(Math.random()*31);
                if(kolekcja.get(rand).statusWypozyczenia==false){
                    ludzie[i].wypozycz(wypozyczone, kolekcja.get(rand));
                    wypozyczone++;
                }
            }
        }
    }
    
    public void zworc(){
        for (int i = 0; i < liczbaLudzi; i++) {
            Czlowiek.Rodzaj r = ludzie[i].rodzaj;
            int j=0;
            switch(r){
                case P:{
                    j=5;
                    break;
                }
                case W:{
                    j=20;
                    break;
                }
                case S:{
                    j = 10;
                    break;
                }
            }
            for (int k = 0; k < j; k++) {
                if(ludzie[i].tablicaWypozyczenia[k] != null){
                    System.out.println("Zwracam");
                    ludzie[i].tablicaWypozyczenia[k].zwroc();
                    this.kolekcja.get(ludzie[i].tablicaWypozyczenia[k].getIndex()).zwroc();
                }
            }
        }
    }
    public void symulacja(){
        System.out.println("Przed wypozyczeniem!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        wyswietlStan();
        wypozycz();
        System.out.println("Po wypozyczeniu!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        wyswietlStan();
        zworc();
        System.out.println("Po zwrocie!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        wyswietlStan();
    }
}
