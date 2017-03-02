/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;

/**
 *
 * @author student
 */
public class Binary {

    public int maxNumberOfZero(int dec) {
        String binary = new String("");
        int maxZero = 0;
        int noZero = 0;
        int n = dec;
        boolean isInSequence = false;
        while (n > 0) {
            if (n % 2 == 1) {
                binary += "1";
                noZero = 0;
                isInSequence = true;
            } else {
                binary += "0";
                noZero++;
            }
            if ((maxZero < noZero) && (isInSequence == true)) {
                maxZero = noZero;
            }
            n = n / 2;
        }
        String binaryReverse = new String("");
        for (int i = binary.length() - 1;
                i >= 0; i--) {
            binaryReverse += binary.charAt(i);
        }
        if (maxZero== 0) {
            System.err.println("brak sekwencji zer");
        }

        System.out.println(
                "Liczba " + dec + " to binarnie: " + binaryReverse);
        return maxZero;
    }
}
