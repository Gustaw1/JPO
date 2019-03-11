/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Animals;

import World.World;
import World.Organism;
import java.util.*;
import javafx.util.Pair;

/**
 *
 * @author Maciek
 */
final public class Mosquito extends Animal {

    public Mosquito() {
        super();
        init();
    }

    public Mosquito(int x, int y) {
        super(x, y);
        init();
    }

    public Mosquito(int x, int y, World world) {
        super(x, y, world);
        init();
    }

    public String get_name() {
        return "Komar";
    }

    protected void spawn_new(int x, int y) {
        super.spawn_new(new Wolf(x, y));
    }

    protected void init() {
        SYMBOL = 'M';
        strength = 1;
        initiative = 1;
    }

    protected void isMosquitoAneighbour() {
   
        Integer x = position.getKey(), y = position.getValue();
        //po prawej
        if (!world.is_free(position.getKey() + 1, position.getValue())) {
            //sprawdzamy czy to komar
            Pair temp_position = new Pair(position.getKey() + 1, position.getValue()); //tymczasowe wspolrzedne
            for (int i = 0; i < world.getOrganisms().size(); ++i) { //porownujemy z organizmami
                //jesli ta sama pozycja i symbol to sila++ i inicjatywa++
                if (temp_position.equals(world.getOrganisms().get(i).pos())
                        && get_uid().equals(world.getOrganisms().get(i).get_uid())
                        && get_symbol() == world.getOrganisms().get(i).get_symbol()) {
                    strength++;
                    initiative++;
                }
            }

        } // po lewej
        else if (!world.is_free(position.getKey() - 1, position.getValue())) {
            //sprawdzamy czy to komar
            Pair temp_position = new Pair(position.getKey() - 1, position.getValue()); //tymczasowe wspolrzedne
            for (int i = 0; i < world.getOrganisms().size(); ++i) { //porownujemy z organizmami
                //jesli ta sama pozycja i symbol to sila++ i inicjatywa++
                if (temp_position.equals(world.getOrganisms().get(i).pos())
                        && get_uid().equals(world.getOrganisms().get(i).get_uid())
                        && get_symbol() == world.getOrganisms().get(i).get_symbol()) {
                    strength++;
                    initiative++;
                }
            }
        } // Poniżej 
        else if (!world.is_free(position.getKey(), position.getValue() + 1)) {
            Pair temp_position = new Pair(position.getKey(), position.getValue() + 1); //tymczasowe wspolrzedne
            for (int i = 0; i < world.getOrganisms().size(); ++i) { //porownujemy z organizmami
                //jesli ta sama pozycja i symbol to sila++ i inicjatywa++
                if (temp_position.equals(world.getOrganisms().get(i).pos())
                        && get_uid().equals(world.getOrganisms().get(i).get_uid())
                        && get_symbol() == world.getOrganisms().get(i).get_symbol()) {
                    strength++;
                    initiative++;
                }
            }
        } // U góry 
        else if (!world.is_free(position.getKey(), position.getValue() - 1)) {
            Pair temp_position = new Pair(position.getKey(), position.getValue() - 1); //tymczasowe wspolrzedne
            for (int i = 0; i < world.getOrganisms().size(); ++i) { //porownujemy z organizmami
                //jesli ta sama pozycja i symbol to sila++ i inicjatywa++
                if (temp_position.equals(world.getOrganisms().get(i).pos())
                        && get_uid().equals(world.getOrganisms().get(i).get_uid())
                        && get_symbol() == world.getOrganisms().get(i).get_symbol()) {
                    strength++;
                    initiative++;
                }
            }
        }
    }

    public void action() {
        isMosquitoAneighbour(); //Sprawdzamy czy jest komar na sasiednim polu
        super.action();
    }

    //50% szans na ucieczke jesli zostanie pokonany, false-zostal, true-uciekl
    protected boolean MosquitoEscaped() {
      Random randomno = new Random();
      boolean value = randomno.nextBoolean();
      return value;    
    }

    protected void fight(Organism oponent) {
        if (strength > oponent.get_strength()) {
            world.kill(this, oponent);
        } else if (strength < oponent.get_strength()) {
            if (MosquitoEscaped()) {
                world.kill(oponent, this);
            }
        } // Siła jest równa, decydują inne czynniki
        else {
            // Zaatakował
            if (initiative < oponent.get_initiative()) {
                world.kill(this, oponent);
            } // Został zaatakowany
            else if (initiative > oponent.get_initiative()) {
                if (MosquitoEscaped()) {
                    world.kill(oponent, this);
                }
            } // Ta sama inicjatywa, ten jest młodszy ? wygrywa
        }
    }
}

