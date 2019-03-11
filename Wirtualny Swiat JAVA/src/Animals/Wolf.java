/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Animals;

/**
 *
 * @author Maciek
 */
import World.World;

final public class Wolf extends Animal {

    public Wolf() {
        super();
        init();
    }

    public Wolf(int x, int y) {
        super(x, y);
        init();
    }

    public Wolf(int x, int y, World world) {
        super(x, y, world);
        init();
    }

    public String get_name() {
        return "Wilk";
    }

    protected void spawn_new(int x, int y) {
        super.spawn_new(new Wolf(x, y));
    }

    protected void init() {
        SYMBOL = 'W';
        strength = 9;
        initiative = 5;
    }          
}