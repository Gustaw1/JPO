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
import Animals.Animal;
import World.Organism;
import World.World;

final public class Guarana extends Plant {

    public Guarana() {
        super();
        init();
    }

    public Guarana(int x, int y) {
        super(x, y);
        init();
    }

    public Guarana(int x, int y, World world) {
        super(x, y, world);
        init();
    }

    public String get_name() {
        return "Guarana";
    }

    public void collision(Organism with) {
        // Zwiększenie siły o 3
        if (with instanceof Animal) {
            ((Animal) with).inc_strength(3);
        }
    }

    protected void spawn_new(int x, int y) {
        super.spawn_new(new Guarana(x, y));
    }

    protected void init() {
        strength = 0;
        SYMBOL = 'u';
    }
}
