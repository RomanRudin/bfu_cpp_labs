#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(100.f, 100.f);

    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        return -1;
    }
    sf::Text text("Hello, SFML!", font, 50);
    text.setPosition(200.f, 200.f);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound.wav")) {
        return -1;
    }
    sf::Sound sound(buffer);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) 
                sound.play();
        }

        window.clear();

        window.draw(circle);
        window.draw(text);

        window.display();
    }
    return 0;
}