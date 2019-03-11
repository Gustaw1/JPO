
import Animals.*;
import Plants.*;
import Other.Controller;
import Other.PaneController;
import Other.SaveData;
import World.Organism;
import World.World;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Random;
import javafx.util.Pair;

public class main extends JFrame implements ActionListener {

    private static int N = 20;
    private static int field_width = 35;
    private World world;
    private JFrame f;
    private JPanel p;
    private JButton bNextRound;
    private JButton bSave;
    private JButton bLoad;
    private JButton bExit;
    private JLabel info;
    private static JPanel panel1;
    private static JPanel panel2;
    public Controller controller1;
    private boolean game_started = false;

    public main() {

        //Ramka glowna
        f = new JFrame("Maciej Kubale nr 120486");
        f.setVisible(true);
        // f.setSize(720, 776);
        f.setSize(958, 776);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //swiat gry
        panel1 = new DrawOnThis();
        panel1.setBackground(new Color(255, 255, 255));
        panel1.setSize(700, 700);
        f.add(panel1, BorderLayout.WEST);

        //panel zdarzen   
        panel2 = new JPanel();
        panel2.setBackground(new Color(226, 226, 226));
        f.add(panel2);

        //panel nawigacji
        p = new JPanel();
        p.setBackground(Color.gray);
        f.add(p, BorderLayout.SOUTH);

        //przyciski
        //next
        bNextRound = new JButton("Start / Next Round");
        bNextRound.setBounds(0, 0, 100, 20);
        p.add(bNextRound);
        // add(bNextRound);
        bNextRound.addActionListener(this);
        //save
        bSave = new JButton("Save");
        bSave.setBounds(100, 0, 100, 20);
        p.add(bSave);
        //add(bSave);
        bSave.addActionListener(this);
        //load
        bLoad = new JButton("Load");
        bLoad.setBounds(200, 0, 100, 20);
        p.add(bLoad);
        // add(bLoad);
        bLoad.addActionListener(this);
        //Exit
        bExit = new JButton("Exit");
        bExit.setBounds(200, 0, 100, 20);
        p.add(bExit);
        // add(bLoad);
        bExit.addActionListener(this);
    }

    public static void main(String[] args) {

        main okno = new main();
    }

    @Override
    public void actionPerformed(ActionEvent ae) {
        Object source = ae.getSource();
        if (source == bNextRound) {
            System.out.println("nowa tura");
            //jesli pierwszy raz klikamy, rysujmy swiat
            if (game_started == false) {
                // Inicjacja świata
                world = new World();
                world.set_N(N);

                controller1 = new PaneController();
                controller1.setField_width(field_width);
                controller1.setMap_panel(panel1);
                controller1.setInfo_panel(panel2);
                world.setController(controller1);

                // Inicjalizacja organizmów
                initOrganisms();
                // world.add_organism(new Wolf(10, 10));
                world.add_pending();
                world.draw_world();
                game_started = true;
            }
            world.nextRound();
        } else if (source == bSave) {
            System.out.println("save");
            if (!game_started) {
                return;
            }
            // Zapis stanu gry do pliku
            SaveData sd = new SaveData();
            try {
                try (PrintWriter writer = new PrintWriter("world.xml", "UTF-8")) {
                    writer.print(sd.write_xml(world));
                }
            } catch (FileNotFoundException | UnsupportedEncodingException e1) {
                e1.printStackTrace();
            }
        } else if (source == bLoad) {
            System.out.println("load");

            world = new SaveData().read_xml(world);
            world.set_N(N);
            controller1 = new PaneController();
            controller1.setField_width(field_width);
            controller1.setMap_panel(panel1);
            controller1.setInfo_panel(panel2);
            world.setController(controller1);
            world.add_pending();
            world.draw_world();
            game_started = true;

        } else if (source == bExit) {
            System.exit(0);
        }
    }

    // Plansza do rysowania
    class DrawOnThis extends JPanel {

        DrawOnThis() {
            setPreferredSize(new Dimension(N * field_width, N * field_width));
        }

        @Override
        public void paintComponent(Graphics g) {

            super.paintComponent(g);
            for (int i = 0; i < N; ++i) {
                g.drawLine(field_width * (i + 1), 0, field_width * (i + 1), N * field_width); // Linie pionowe
                g.drawLine(0, field_width * (i + 1), N * field_width, field_width * (i + 1)); // Linie poziome
            }
        }
    }

    //losowanie organizmow (po 5 szt.)
    private <T extends Organism> void initOrganism(Class<T> cls) throws IllegalAccessException, InstantiationException {
        Random rand = new Random();
        for (int i = 0; i < 5;) {
            int x = rand.nextInt(N), y = rand.nextInt(N);
            if (world.is_free(x, y)) {
                T elem = cls.newInstance();
                elem.setPosition(new Pair(x, y));
                world.add_organism(elem);
                ++i;
            }
        }
    }

    //sprawdzanie wyjatkow
    private void initOrganisms() {
        try {
            // Zwierzęta                    
            initOrganism(Sheep.class); // Owca
            initOrganism(Wolf.class); // Wilk
            initOrganism(Mosquito.class); // komar
            initOrganism(Snail.class); // slimak
            initOrganism(Elephant.class); // slon

            // Rośliny
            initOrganism(Grass.class); // Trawa
            initOrganism(Guarana.class); // Guarana
            initOrganism(Wolfberries.class); // Wilcze jagody

        } catch (IllegalAccessException | InstantiationException e) {
        }
    }
}
