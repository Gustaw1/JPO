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

final public class Wolfberries extends Plant {

    public Wolfberries() {
        super();
        init();
    }

    public Wolfberries(int x, int y) {
        super(x, y);
        init();
    }

    public Wolfberries(int x, int y, World world) {
        super(x, y, world);
        init();
    }

    public String get_name() {
        return "Wilcze Jagody";
    }

    public void collision(Organism with) {
        // Przeciwnik ginie
        kill(with);
    }

    protected void spawn_new(int x, int y) {
        super.spawn_new(new Wolfberries(x, y));
    }

    protected void init() {
        strength = 0;
        SYMBOL = 'b';
    }
}
