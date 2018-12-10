/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package auxiliar;

import java.util.Random;

/**
 *
 * @author Darks
 */
public class LogicaJuego {
    
    public int[] getCardNumbers() {
        
        int[] numbers = new int[40];
        int count = 0;
        
        while(count < 40) {
            Random r = new Random();
            int na = r.nextInt(20) + 1;
            int nvr = 0;
            
            for (int i = 0; i < 40; i++) {
                if(numbers[i] == na) {
                    nvr++;
                }
            }
            if(nvr < 2) {
                numbers[count] = na;
                count++;
            }//fin
        }
        return numbers;
    }
            
}
