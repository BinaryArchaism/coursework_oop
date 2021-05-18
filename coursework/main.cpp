#include <SFML/Graphics.hpp>
#include <iostream>
#include "hero.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dungeon master", sf::Style::Close);
    window.setFramerateLimit(60);
    hero hero_one = hero();
    sf::Texture background;
    background.loadFromFile("images/background.png");
    sf::Sprite back_sprite;
    back_sprite.setTexture(background);
    sf::View camera(sf::Vector2f(350.f, 300.f), sf::Vector2f(800.f, 600.f));
    camera.setCenter(hero_one.getX(), hero_one.getY());
    float camera_zoom = 0.5f;

    sf::Font font;
    font.loadFromFile("images/NormalFont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(36);
    text.setString("Moisha");

    sf::CircleShape shape(3.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
            
        camera.setSize(800.f * camera_zoom, 600.f * camera_zoom);
        window.setView(camera);
        //text.setPosition(camera.getCenter().x-100, camera.getCenter().y - 100);

        
            window.draw(back_sprite);
            hero_one.show(&window);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                hero_one.moveRight(); 
                camera.setCenter(hero_one.getX(), hero_one.getY());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                hero_one.moveLeft();
                camera.setCenter(hero_one.getX(), hero_one.getY());
            }
                
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                hero_one.moveUp();
                camera.setCenter(hero_one.getX(), hero_one.getY());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                hero_one.moveDown();
                camera.setCenter(hero_one.getX(), hero_one.getY());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
                camera_zoom = 0.5f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen)) {
                camera_zoom = 0.6f;
            }
            shape.setPosition(camera.getCenter());
            //window.draw(shape);
            //window.draw(text);

        window.display();
    }
    return 0;
}