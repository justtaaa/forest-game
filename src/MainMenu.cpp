#include "MainMenu.h"

MainMenu::MainMenu(const sf::Font& font)
        : startButton("Start", {100, 100}, font), // Initialize with parameters
          optionsButton("Options", {100, 150}, font) // Initialize with parameters
{
    // Set actions for the buttons after they are constructed
    startButton.setAction([&](){
        // Start game action
    });

    optionsButton.setAction([&](){
        // Options action
    });

    // Continue adding actions for other buttons if you have more...
}

void MainMenu::draw(sf::RenderWindow& window) {
    // Draw buttons
    startButton.draw(window);
    optionsButton.draw(window);
    // Draw other menu items...
}

void MainMenu::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    // Delegate event handling to buttons
    startButton.handleEvent(event, window);
    optionsButton.handleEvent(event, window);
    // Handle events for other menu items...
}
