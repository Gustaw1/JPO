package World;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Maciek
 */
import javafx.util.Pair;
import Other.NoPlaceToSpawn;

import java.time.Instant;
import java.util.UUID;

public abstract class Organism {

    protected World world;
    protected int strength;
    protected int initiative;
    protected Pair<Integer, Integer> position;
    UUID uid;
    protected char SYMBOL = '?';
    long creation;
    protected Pair<Integer, Integer> last_position;

    protected Organism(int x, int y, World world) {
        setPosition(new Pair(x, y));
        creation = Instant.now().getEpochSecond();
        uid = UUID.randomUUID();
        this.world = world;
        last_position = new Pair(x, y);
    }

    protected abstract void init();

    protected abstract void spawn_new(int x, int y);

    protected void spawn_new(Organism o) {
        world.add_organism(o);
    }

    public void setPosition(Pair<Integer, Integer> position) {
        this.position = position;
    }

    protected Organism(int x, int y) {
        this(x, y, new World());
    }

    protected Organism() {
        this(0, 0, new World());
    }

    public void set_world(World world) {
        this.world = world;
    }

    public void action() {
    }

    public void collision(Organism with) {
    }

    public void collision_default(Organism with) throws NoPlaceToSpawn {
    }

    public Pair<Integer, Integer> pos() {
        return position;
    }

    public void draw() {
        world.getController().print(position.getKey(), position.getValue(), String.valueOf(SYMBOL));
    }

    public int get_initiative() {
        return initiative;
    }

    public int get_strength() {
        return strength;
    }

    public Pair<Integer, Integer> getPosition() {
        return position;
    }

    public abstract String get_name();

    public UUID get_uid() {
        return uid;
    }

    public char get_symbol() {
        return SYMBOL;
    }

    public long get_creation() {
        return creation;
    }

    public Pair<Integer, Integer> get_lastposition() {
        return last_position;
    }

    protected void kill(Organism o) {
        world.kill(this, o);
    }

    protected void eat(Organism o) {
        world.eat(this, o);
        // Wywołanie kolizji aby zmodyfikować ten organizm
        o.collision(this);
    }

    protected void fight(Organism oponent) {
        if (strength > oponent.strength) {
            world.kill(this, oponent);
        } else if (strength < oponent.strength) {
            world.kill(oponent, this);
        } // Siła jest równa, decydują inne czynniki
        else {
            // Zaatakował
            if (initiative < oponent.initiative) {
                world.kill(this, oponent);
            } // Został zaatakowany
            else if (initiative > oponent.initiative) {
                world.kill(oponent, this);
            } // Ta sama inicjatywa, ten jest młodszy ? wygrywa
            else if (creation < oponent.creation) {
                world.kill(this, oponent);
            } // Ta sama inicjatywa, ten jest starszy ? przegrywa
            else if (creation > oponent.creation) {
                world.kill(oponent, this);
            }
        }
    }
}
