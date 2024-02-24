#include <SFML/Graphics.hpp>

int main() {
    // Create the main game window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    window.setFramerateLimit(60);

    // Use SFML's default font
    sf::Font font;
    if (!font.loadFromFile("/Users/taisiianekrasova/CLionProjects/forest-game/resources/fonts/SourceCodePro-BlackItalic.ttf")) {
        // Handle error - exit or use a fallback
        return EXIT_FAILURE;
    }

    // Create a text object with the default font
    sf::Text text("Hello, SFML!", font, 30); // 30 is the character size
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100); // Position the text at x=100, y=100

    // Main loop that continues until we close the window
    while (window.isOpen()) {
        sf::Event event;
        // Process events
        while (window.pollEvent(event)) {
            // Close the window when a close event is received
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with a black color
        window.clear(sf::Color::Black);

        // Draw the text
        window.draw(text);

        // Display what was drawn during this frame
        window.display();
    }

    return 0;
}
