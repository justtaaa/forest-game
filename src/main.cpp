#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/Users/taisiianekrasova/CLionProjects/forest-game/resources/fonts/SourceCodePro-Bold.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }


    MainMenu mainMenu(font, window.getSize());

    sf::Clock clock; // Start a clock to track elapsed time

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time deltaTime = clock.restart(); // Restart the clock and save the elapsed time since the last frame

        mainMenu.update(deltaTime, window); // Update the main menu, passing in the delta time

        window.clear();
        mainMenu.draw(window); // Draw the main menu (which should now be updated)
        window.display();
    }

    return 0;
}
