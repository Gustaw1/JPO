/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Other;

/**
 *
 * @author Maciek
 */
public class NoPlaceToSpawn extends Exception {
    public NoPlaceToSpawn() {
        super("Świat: "+ "Nie można stworzyć potomka");
    }
    
}
