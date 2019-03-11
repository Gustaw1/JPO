/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Plants;

/**
 *
 * @author Maciek
 */
import World.Organism;
import World.World;

abstract public class Plant extends Organism {

    Plant(int x, int y, World world) {
        super(x, y, world);
        initiative = 0;
    }

    Plant(int x, int y) {
        super(x, y);
        initiative = 0;
    }

    Plant() {
        super();
        initiative = 0;
    }

    public void action() {
        if (world.getRand_class().nextInt(4) == 1) { // 25% szans na rozsianie
            Integer x = position.getKey(), y = position.getValue();
            // Po prawej jest miejsce
            if (world.is_free(position.getKey() + 1, position.getValue())) {
                ++x;
            } // Po lewej jest miejsce
            else if (world.is_free(position.getKey() - 1, position.getValue())) {
                --x;
            } // Poniżej jest miejsce
            else if (world.is_free(position.getKey(), position.getValue() + 1)) {
                ++y;
            } // U góry jest miejsce
            else if (world.is_free(position.getKey(), position.getValue() - 1)) {
                --y;
            }
            spawn_new(x, y);
        }
    }
}
