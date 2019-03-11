/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Other;

import World.Organism;
import World.World;
import java.io.File;
import java.io.IOException;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 *
 * @author Maciek
 */
public class SaveData implements Data {

    @Override
    public World read_xml(Object o) {
        World world = new World();

        File XML = new File("world.xml");
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder;
        try {
            dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(XML);
            doc.getDocumentElement().normalize();

            // Przetwarzanie dokumentu
            world.set_N(Integer.parseInt(doc.getDocumentElement().getAttribute("size")));
            // Organizmy
            NodeList organisms = doc.getElementsByTagName("organism");
            OrganismList ol = new OrganismList();
            for (int i = 0; i < organisms.getLength(); ++i) {
                Organism org = ol.read_xml(organisms.item(i));
                if (org != null) {
                    world.add_organism(org);
                }
            }
            return world;
        } catch (ParserConfigurationException e) {
        } catch (SAXException | IOException e) {
            e.printStackTrace();
        }

        return null;
    }

    @Override
    public String write_xml(Object o) {
        World w = (World) o;
        OrganismList om = new OrganismList();

        String size_xml = "<world size=\"" + w.get_N() + "\">";
        for (Organism org : w.getOrganisms()) {
            size_xml += om.write_xml(org);
        }
        size_xml += "</world>";

        return size_xml;
    }
}
