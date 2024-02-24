//
// Created by Taisiia Nekrasova on 24/02/2024.
//

#ifndef FOREST_GAME_MAINMENU_H
#define FOREST_GAME_MAINMENU_H


#include "Button.h" // Include the Button header

class MainMenu {
public:
    MainMenu(const sf::Font& font);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);

private:
    Button startButton;
    Button optionsButton;
    // Other members...
};

#endif
