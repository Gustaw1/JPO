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
import World.World;

final public class Grass extends Plant {

    public Grass() {
        super();
        init();
    }

    public Grass(int x, int y) {
        super(x, y);
        init();
    }

    public Grass(int x, int y, World world) {
        super(x, y, world);
        init();
    }

    public String get_name() {
        return "Trawa";
    }

    protected void spawn_new(int x, int y) {
        super.spawn_new(new Grass(x, y));
    }

    protected void init() {
        strength = 0;
        SYMBOL = 'g';
    }
}
