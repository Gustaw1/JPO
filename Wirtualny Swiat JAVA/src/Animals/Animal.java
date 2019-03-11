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
import World.Organism;
import World.World;
import javafx.util.Pair;
import Other.NoPlaceToSpawn;

abstract public class Animal extends Organism {

    Animal() {
        super();
        last_position = position;
    }

    Animal(int x, int y) {
        super(x, y);
        last_position = position;
    }

    Animal(int x, int y, World world) {
        super(x, y, world);
        last_position = position;
    }
    
        public void inc_strength(int s) {
        strength += s;
    } //zwiekszenie sily

    void go_back() {
        setPosition(last_position);
    }      //powrot na poprzednia pozycje

    protected enum DIRECTIONS {
        TOP, BOTTOM, LEFT, RIGHT
    } //4 kierunki


    void move_x(DIRECTIONS d) {
        if (d.equals(DIRECTIONS.LEFT)) {// Przesunięcie w lewo

            if (position.getKey() - 1 >= 0) {
                setPosition(new Pair(position.getKey() - 1, position.getValue()));
            }

        }
        if (d.equals(DIRECTIONS.RIGHT)) { // Przesunięcie w prawo

            if (position.getKey() + 1 < world.get_N()) {
                setPosition(new Pair(position.getKey() + 1, position.getValue()));
            }
        }
    }

    void move_y(DIRECTIONS d) {
        if (d.equals(DIRECTIONS.TOP)) { // Przesunięcie w górę

            if (position.getValue() - 1 >= 0) {
                setPosition(new Pair(position.getKey(), position.getValue() - 1));
            }
        } else { // Przesunięcie w dół

            if (position.getValue() + 1 < world.get_N()) {
                setPosition(new Pair(position.getKey(), position.getValue() + 1));
            }
        }
    }

    @Override
    public void action() {
        // Przesuniecie zwierzaka
        int r = world.getRand_class().nextInt(4);
        switch (r) {
            case 0:
                move_y(DIRECTIONS.TOP);
                break;
            case 1:
                move_y(DIRECTIONS.BOTTOM);
                break;
            case 2:
                move_x(DIRECTIONS.LEFT);
                break;
            case 3:
                move_x(DIRECTIONS.RIGHT);
                break;
            default:
                break;
        }
        super.action();
    }

    public void collision(Organism with) {
    }

    boolean should_fight(Animal with) {
        return true;
    }

    public void collision_default(Organism with) throws NoPlaceToSpawn {
        // Ten sam typ ? rozmnażanie
        if (get_symbol() == with.get_symbol()) {
            // Po lewej jest wolne miejsce
            if (world.is_free(position.getKey() - 1, position.getValue())) {
                spawn_new(position.getKey() - 1, position.getValue());
            } // Po prawej jest wolne miejsce
            else if (world.is_free(position.getKey() + 1, position.getValue())) {
                spawn_new(position.getKey() + 1, position.getValue());
            } // U góry jest wolne miejsce
            else if (world.is_free(position.getKey(), position.getValue() - 1)) {
                spawn_new(position.getKey(), position.getValue() - 1);
            } // Na dole jest wolne miejsce
            else if (world.is_free(position.getKey(), position.getValue() + 1)) {
                spawn_new(position.getKey(), position.getValue() + 1);
            } else {
                throw new NoPlaceToSpawn();
            }
            world.add_event(get_name() + " się rozmnaża");
        } else {
            // Inne gatunki - będzie walka
            if (with instanceof Animal) {
                // Zwierzęta powinny walczyć
                if (should_fight((Animal) with) && ((Animal) with).should_fight(this)) {
                    fight(with);
                } // Niestandardowa akcja kolizji
                else {
                    collision(with);
                    with.collision(this);
                }
            } // Nie jest zwierzęciem -> będzie jedzone
            else {
                eat(with);
            }
        }
    }

    protected void eat(Organism p) {
        super.eat(p);
    }

}
