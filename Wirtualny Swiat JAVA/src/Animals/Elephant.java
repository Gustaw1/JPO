package Animals;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import World.World;

final public class Elephant extends Animal {

    public Elephant() {
        super();
        init();
    }

    public Elephant(int x, int y) {
        super(x, y);
        init();
    }

    public Elephant(int x, int y, World world) {
        super(x, y, world);
        init();
    }

    public String get_name() {
        return "Slon";
    }

    protected void spawn_new(int x, int y) {
        super.spawn_new(new Elephant(x, y));
    }

    protected void init() {
        SYMBOL = 'E';
        strength = 7;
        initiative = 2;
    }          
    
    public void action() {
        // 50% szans na ruch
        if (world.getRand_class().nextInt(2) == 1) {
            super.action();
        }
    }
	
	 protected boolean should_fight(Animal with) {
		 //niewrazliwy na ataki o sile 1
        return !(with.get_strength() == 1);
}