//
// Created by Taisiia Nekrasova on 24/02/2024.
//

#ifndef FOREST_GAME_BUTTON_H
#define FOREST_GAME_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

class Button {
public:
    Button(const std::string& text, const sf::Vector2f& position, const sf::Font& font);
    void setAction(const std::function<void()>& action);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);

private:
    sf::RectangleShape background;
    sf::Text text;
    std::function<void()> action; // The action to take when the button is clicked
};

#endif // BUTTON_H
