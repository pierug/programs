/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolos2;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

/**
 *
 * @author pieru
 */
public class SklepInternetowy {
    private final int liczbaOfert = 5;
    public Komputer[] oferta;
    public ArrayList<Zamowienie> listaZamowien;

    public SklepInternetowy() {
        oferta = new Komputer[liczbaOfert];
        oferta[0] = new Laptop("LiOn 1", "15`", "15Mpx", "Asus", "i5", "300GB", "Invida 1080p");
        oferta[1] = new Laptop("LiOn 2", "20`", "16Mpx", "HP", "i3", "200GB", "Invida 980p");
        oferta[2] = new Laptop("LiOn 3", "19`", "14Mpx", "Lenowo", "i7", "400GB", "Invida 780p");
        oferta[3] = new Smartphone("Galaxy", "Amd", "16Gb", "250Mb");
        oferta[4] = new Smartphone("Iphon", "ARM", "32Gb", "500Mb");
        
        listaZamowien = new ArrayList<>();
    }

    
    void zamow(String klient, Komputer towar, int ilosc){
        System.out.println("Wybrane towary przed zamowieniem dla klienta: "+klient);
        for (int i = 0; i < liczbaOfert; i++) {
            if(oferta[i].equals(towar)){
                listaZamowien.add(new Zamowienie(i, ilosc, klient));
                System.out.println(listaZamowien.get(listaZamowien.size()-1).toString());
                System.out.println(towar.toString());
                break;
            }
        }
    }
    
    void zrealizuj(String klient){
        System.out.println("Realizowanie zamowienia dla klienta: "+klient);
        for (int i = 0; i < listaZamowien.size(); i++) {
            if(listaZamowien.get(i).getKlient().equals(klient)&&((listaZamowien.get(i).isStatusRealizacji()==false))){
                Calendar calendar = Calendar.getInstance();
                listaZamowien.get(i).setDataZamowienia(calendar.getTime());
                listaZamowien.get(i).setStatusRealizacji(true);
                System.out.println(listaZamowien.get(i).toString());
            }
        }
    }
    
    public class Zamowienie{
                
        private int index;
        private int iloscSztuk;
        private String klient;

        @Override
        public String toString() {
            return "Zamowienie{" + "index=" + index + ", iloscSztuk=" + iloscSztuk + ", klient=" + klient + ", dataZamowienia=" + dataZamowienia + ", statusRealizacji=" + statusRealizacji + '}';
        }
        
        private Date dataZamowienia;
        private boolean statusRealizacji;

        public int getIndex() {
            return index;
        }

        public void setIndex(int index) {
            this.index = index;
        }

        public int getIloscSztuk() {
            return iloscSztuk;
        }

        public void setIloscSztuk(int iloscSztuk) {
            this.iloscSztuk = iloscSztuk;
        }

        public String getKlient() {
            return klient;
        }

        public void setKlient(String klient) {
            this.klient = klient;
        }

        public Date getDataZamowienia() {
            return dataZamowienia;
        }

        public void setDataZamowienia(Date dataZamowienia) {
            this.dataZamowienia = dataZamowienia;
        }

        public boolean isStatusRealizacji() {
            return statusRealizacji;
        }

        public void setStatusRealizacji(boolean statusRealizacji) {
            this.statusRealizacji = statusRealizacji;
        }

        public Zamowienie(int index, int iloscSztuk, String klient) {
            this.index = index;
            this.iloscSztuk = iloscSztuk;
            this.klient = klient;
            this.statusRealizacji = false;
            this.dataZamowienia = null;
        }
    }
}

