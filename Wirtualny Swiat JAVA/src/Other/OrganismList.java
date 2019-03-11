/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Other;

import Animals.*;
import Plants.*;
import World.Organism;
import org.w3c.dom.Element;
import org.w3c.dom.Node;

/**
 *
 * @author Maciek
 */
public class OrganismList implements Data {

    // Wczytywanie stanu z XMLa
    @Override
    public Organism read_xml(Object o) {
        Node node = (Node) o;
        if (node.getNodeType() == Node.ELEMENT_NODE) {
            // Node opisujący organizm
            Element org = (Element) node;
            Organism res = null;
            final int POS_X = Integer.parseInt(org.getAttribute("pos_x")), POS_Y = Integer.parseInt(org.getAttribute("pos_y"));
            switch (org.getAttribute("symbol").charAt(0)) {
                // Zwierzęta
                case 'W':
                    res = new Wolf(POS_X, POS_Y);
                    break;
                case 'N':
                    res = new Snail(POS_X, POS_Y);
                    break;
                case 'S':
                    res = new Sheep(POS_X, POS_Y);
                    break;
                case 'M':
                    res = new Mosquito(POS_X, POS_Y);
                    break;
                case 'E':
                    res = new Elephant(POS_X, POS_Y);
                    break;
                // Rośliny
                case 'b':
                    res = new Wolfberries(POS_X, POS_Y);
                    break;
                case 'g':
                    res = new Grass(POS_X, POS_Y);
                    break;
                case 'u':
                    res = new Guarana(POS_X, POS_Y);
                    break;
            }
            if (res != null) {
                return res;
            }
        }
        return null;
    }

    // Zapisywanie stanu do XMLa
    @Override
    public String write_xml(Object o) {
        Organism org = (Organism) o;
        String res_xml = "<organism";
        res_xml += " uid=\"" + org.get_uid() + "\"";
        res_xml += " strength=\"" + org.get_strength() + "\"";
        res_xml += " initiative=\"" + org.get_initiative() + "\"";
        res_xml += " creation=\"" + org.get_creation() + "\"";
        res_xml += " symbol=\"" + org.get_symbol() + "\"";
        res_xml += " pos_x=\"" + org.pos().getKey() + "\" pos_y=\"" + org.pos().getValue() + "\"";
        res_xml += " last-pos_x=\"" + org.get_lastposition().getKey() + "\" last-pos_y=\"" + org.get_lastposition().getValue() + "\"";

        res_xml += "></organism>";

        return res_xml;
    }

}
