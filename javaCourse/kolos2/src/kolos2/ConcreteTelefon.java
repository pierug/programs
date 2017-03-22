package kolos2;
public class ConcreteTelefon implements Telefon{
    
    private String[][] ksiazkaTelefoniczna;
    private final int numOfTel = 20;
    private static int index;
    
    public ConcreteTelefon() {
        index = 0;
        ksiazkaTelefoniczna = new String[numOfTel][2];
        
    }
    @Override
    public void dodajKontakt(String nazwa, String telefon){
        if(index<numOfTel){
            ksiazkaTelefoniczna[index][0]=nazwa;
            ksiazkaTelefoniczna[index][1]=telefon;
            index++;
        }else{
            System.out.println("Nie ma juz miejsca w tablicy");
        }
    }
    @Override
    public String wyszukajKontakt(String nazwa){
        for (int i = 0; i < numOfTel; i++) {
            if(ksiazkaTelefoniczna[i][0].equals(nazwa)){
                return ksiazkaTelefoniczna[i][1];
            }
        }
        return "Nie ma takiego numeru";
    }
}
