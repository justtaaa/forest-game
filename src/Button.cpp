#include "Button.h"

Button::Button(const std::string& text, const sf::Vector2f& position, const sf::Font& font)
        : action([](){}), // Initialize the action to an empty lambda function
          text(text, font) { // Initialize the sf::Text member with the string and font
    this->text.setCharacterSize(24); // Set character size
    this->text.setPosition(position); // Set text position

    // Calculate the size of the button based on the text
    background.setSize(sf::Vector2f(this->text.getLocalBounds().width + 20, this->text.getLocalBounds().height + 20));
    background.setPosition(position - sf::Vector2f(10, 10)); // Offset a bit for padding
    background.setFillColor(sf::Color::Transparent);
    background.setOutlineColor(sf::Color::White);
    background.setOutlineThickness(2.0f);
}


void Button::setAction(const std::function<void()>& action) {
    this->action = action; // Assign the provided action to the member variable
}


void Button::draw(sf::RenderWindow& window) {
    window.draw(background); // Draw the button's background
    window.draw(text); // Draw the button's text
}


void Button::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    // Check if the event is a mouse button press
    if (event.type == sf::Event::MouseButtonPressed) {
        // Convert the mouse position to world coordinates and check if it's inside the button's bounds
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (background.getGlobalBounds().contains(mousePos)) {
            action(); // If so, execute the button's action
        }
    }
}

bool Button::isHovered(const sf::RenderWindow& window) const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return background.getGlobalBounds().contains(window.mapPixelToCoords(mousePos));
}


void Button::update(const sf::RenderWindow& window) {
    if (isHovered(window)) {
        background.setFillColor(sf::Color::White); // Change color on hover
        text.setFillColor(sf::Color::Black);
    } else {
        background.setFillColor(sf::Color::Transparent);
        text.setFillColor(sf::Color::White);
    }
}