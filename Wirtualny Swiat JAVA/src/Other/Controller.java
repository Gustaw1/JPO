/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Other;

import javax.swing.*;

/**
 *
 * @author Maciek
 */
public interface Controller {

    // Wyświetlanie na planszy
    void print(int x, int y, String text);

    // Czyszczenie informacji dodatkowych
    void clear_info();

    // Wyświetlanie informacji dodatkowych
    void print_info(String text);

    //Ustawienie paneli
    void setMap_panel(JPanel p);

    void setInfo_panel(JPanel p);

    void setField_width(int w);
}
