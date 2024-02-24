#ifndef FOREST_GAME_MAINMENU_H
#define FOREST_GAME_MAINMENU_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h" // Include the Button header

class MainMenu {
public:
    MainMenu(const sf::Font& font, const sf::Vector2u& windowSize);
    void update(const sf::Time& deltaTime, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);

private:
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    std::vector<Button> buttons;
    float backgroundScrollSpeed;
    sf::RectangleShape fadeOverlay;
    bool isTransitioning;
    float transitionSpeed;


};

#endif
