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
public class Laptop extends Komputer {
    
    private String bateria;
    private String przekatnaEkranu;
    private String kamera;

    public String getBateria() {
        return bateria;
    }

    public void setBateria(String bateria) {
        this.bateria = bateria;
    }

    public String getPrzekatnaEkranu() {
        return przekatnaEkranu;
    }

    public void setPrzekatnaEkranu(String przekatnaEkranu) {
        this.przekatnaEkranu = przekatnaEkranu;
    }

    public String getKamera() {
        return kamera;
    }

    public void setKamera(String kamera) {
        this.kamera = kamera;
    }

    public Laptop(String bateria, String przekatnaEkranu, String kamera, String nazwa, String procesor, String dysk, String kartaGraficzna) {
        
        super(nazwa, Rodzaj.laptop , procesor, dysk, kartaGraficzna);
        this.bateria = bateria;
        this.przekatnaEkranu = przekatnaEkranu;
        this.kamera = kamera;
    }
    
}
