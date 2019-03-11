/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Animals;

import World.World;

/**
 *
 * @author Maciek
 */

final public class Sheep extends Animal {

    public Sheep() {
        super();
        init();
    }

    public Sheep(int x, int y) {
        super(x, y);
        init();
    }

    public Sheep(int x, int y, World world) {
        super(x, y, world);
        init();
    }

    public String get_name() {
        return "Owca";
    }

    protected void spawn_new(int x, int y) {
        super.spawn_new(new Sheep(x, y));
    }

    protected void init() {
        SYMBOL = 'S';
        strength = 4;
        initiative = 4;
    }
}
