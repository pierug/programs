/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolos2;

/**
 *
 * @author pieru
 */
public class Komputer {
    public enum Rodzaj{laptop,telefon}

    public String getNazwa() {
        return nazwa;
    }

    public void setNazwa(String nazwa) {
        this.nazwa = nazwa;
    }

    public Rodzaj getRodzaj() {
        return rodzaj;
    }

    public void setRodzaj(Rodzaj rodzaj) {
        this.rodzaj = rodzaj;
    }

    public String getProcesor() {
        return procesor;
    }

    public void setProcesor(String procesor) {
        this.procesor = procesor;
    }

    public String getDysk() {
        return dysk;
    }

    public void setDysk(String dysk) {
        this.dysk = dysk;
    }

    public String getKartaGraficzna() {
        return kartaGraficzna;
    }

    public void setKartaGraficzna(String kartaGraficzna) {
        this.kartaGraficzna = kartaGraficzna;
    }

    public Komputer(String nazwa, Rodzaj rodzaj, String procesor, String dysk, String kartaGraficzna) {
        this.nazwa = nazwa;
        this.rodzaj = rodzaj;
        this.procesor = procesor;
        this.dysk = dysk;
        this.kartaGraficzna = kartaGraficzna;
    }

    @Override
    public String toString() {
        return "Komputer{" + "nazwa=" + nazwa + ", rodzaj=" + rodzaj + ", procesor=" + procesor + ", dysk=" + dysk + ", kartaGraficzna=" + kartaGraficzna + '}';
    }
    private String nazwa;
    private Rodzaj rodzaj;
    private String procesor;
    private String dysk;
    private String kartaGraficzna;
}
