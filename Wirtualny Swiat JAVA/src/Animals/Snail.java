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
import Other.NoPlaceToSpawn;
import World.Organism;
import World.World;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.util.Pair;

final public class Snail extends Animal {

    public Snail() {
        super();
        init();
    }

    public Snail(int x, int y) {
        super(x, y);
        init();
    }

    public Snail(int x, int y, World world) {
        super(x, y, world);
        init();
    }

    public String get_name() {
        return "Slimak";
    }

    protected void spawn_new(int x, int y) {
        super.spawn_new(new Snail(x, y));
    }

    protected void init() {
        SYMBOL = 'N';
        strength = 1;
        initiative = 1;
    }

    public void action() {
        // 10% szans na ruch
        if (world.getRand_class().nextInt(10) == 1) {
            super.action();
        }
    }

    //Niewrażliwy na ataki zwierząt o sile <2. Ma 60% szans iż pozostanie niezauważony przez zwierzęta o sile >4. 
    //W obu przypadkach napastnik przesuwa się na inne niezajęte pole.
    protected boolean should_fight(Animal with) {
        return !(with.get_strength() < 2 || (world.getRand_class().nextInt(10) <= 6) && (with.get_strength() > 4));
    }

    public void collision(Organism with) {
        if (with instanceof Animal) {
            ((Animal) with).go_back();
            world.add_event("Slimak nie zostal zauwazony przez " + with.get_name());

            // Po lewej jest wolne miejsce
            if (world.is_free(with.getPosition().getKey() - 1, with.getPosition().getValue())) {

                with.setPosition(new Pair(with.getPosition().getKey() - 1, with.getPosition().getValue()));

            } // Po prawej jest wolne miejsce
            else if (world.is_free(with.getPosition().getKey() + 1, with.getPosition().getValue())) {
                with.setPosition(new Pair(with.getPosition().getKey() + 1, with.getPosition().getValue()));

            } // U góry jest wolne miejsce
            else if (world.is_free(with.getPosition().getKey(), with.getPosition().getValue() - 1)) {
                with.setPosition(new Pair(with.getPosition().getKey(), with.getPosition().getValue() - 1));

            } // Na dole jest wolne miejsce
            else if (world.is_free(with.getPosition().getKey(), with.getPosition().getValue() + 1)) {
                with.setPosition(new Pair(with.getPosition().getKey(), with.getPosition().getValue() + 1));

            } else {
                try {
                    throw new NoPlaceToSpawn();
                } catch (NoPlaceToSpawn ex) {
                    Logger.getLogger(Snail.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
    }
}
