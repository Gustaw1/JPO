/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Other;

import javax.swing.*;
import java.awt.*;

/**
 *
 * @author Maciek
 */
public class PaneController implements Controller {

    private JPanel map_panel;
    private JPanel info_panel;

    private int field_width;
    private int info_count = 0;

    public void print(int x, int y, String text) {
        Color box_color = Color.white;
        // Zwierzęta
        if (text.equals("W")) {
            box_color = new Color(0, 0, 0); //wilk czarny
        } else if (text.equals("N")) {
            box_color = new Color(255, 0, 0); //slimak czerwony
        } else if (text.equals("M")) {
            box_color = new Color(25, 19, 246);//komar niebieski
        } else if (text.equals("S")) {
            box_color = new Color(254, 127, 0); //owca pomaranczowy
        } else if (text.equals("E")) {
            box_color = new Color(226, 8, 105); // slon rozowy
        } // Rośliny
        else if (text.equals("b")) {
            box_color = new Color(255, 255, 0); //wilcze jagody zolte   
        } else if (text.equals("g")) {
            box_color = new Color(0, 255, 0); //trawa zielone
        } else if (text.equals("u")) {
            box_color = new Color(74, 74, 74); //guarana szare
        }
        // Rysowanie czegoś
        Graphics g = map_panel.getGraphics();
        g.setColor(box_color);
        g.fillRect(x * field_width + 1, y * field_width + 1, field_width - 1, field_width - 1);
    }

    public void clear_info() {
        info_count = 0;
        if (info_panel != null) {
            info_panel.removeAll();
            info_panel.updateUI();
        }
    }

    public void print_info(String text) {
        ++info_count;
        int MSG_LIMIT = 30;
        if (info_count < MSG_LIMIT) {
            info_panel.add(new JLabel(text, SwingConstants.RIGHT));
        } // Jeśli osiągnęliśmy limit komunikatów, więcej nie wyświetlamy
        else if (info_count == MSG_LIMIT) {
            info_panel.add(new JLabel("...", SwingConstants.RIGHT));
        }
        info_panel.updateUI();
    }

    public void setMap_panel(JPanel p) {
        map_panel = p;
    }

    public void setInfo_panel(JPanel p) {
        info_panel = p;
    }

    public void setField_width(int w) {
        field_width = w;
    }
}
