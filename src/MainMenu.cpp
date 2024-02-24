#include "MainMenu.h"


MainMenu::MainMenu(const sf::Font& font, const sf::Vector2u& windowSize) {
    // Load background texture and set up sprite
    if (!backgroundTexture.loadFromFile("/Users/taisiianekrasova/CLionProjects/forest-game/resources/pictures/1.png")) {
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundScrollSpeed = 50.f;
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));

    // Initialize buttons with font, position, and text
    buttons.emplace_back("Start Game", sf::Vector2f(100, 300), font);
    buttons.emplace_back("Options", sf::Vector2f(100, 400), font);


    // Set up button actions
    for (auto& button : buttons) {
        button.setAction([]() {
            // Button action
        });
    }

    isTransitioning = true;
    transitionSpeed = 255.f;
    fadeOverlay.setSize(static_cast<sf::Vector2f>(windowSize));
    fadeOverlay.setFillColor(sf::Color(0, 0, 0, 255));

}

void MainMenu::update(const sf::Time& deltaTime, const sf::RenderWindow& window) {

    if (isTransitioning) {
        sf::Color overlayColor = fadeOverlay.getFillColor();
        float deltaSeconds = deltaTime.asSeconds();
        overlayColor.a -= static_cast<sf::Uint8>(transitionSpeed * deltaSeconds);
        if (overlayColor.a <= 0) {
            overlayColor.a = 0;
            isTransitioning = false;
        }
        fadeOverlay.setFillColor(overlayColor);
    }

    sf::IntRect textureRect = backgroundSprite.getTextureRect();
    textureRect.left += static_cast<int>(backgroundScrollSpeed * deltaTime.asSeconds());
    backgroundSprite.setTextureRect(textureRect);

    for (auto& button : buttons) {
        button.update(window);
    }
}

void MainMenu::draw(sf::RenderWindow& window) {
    // Draw buttons
    window.draw(backgroundSprite); // Draw the background first
    for (auto& button : buttons) {
        button.draw(window); // Draw each button
    }

}

void MainMenu::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    for (auto &button: buttons) {
        button.handleEvent(event, window); // Handle events for each button
    }
}
