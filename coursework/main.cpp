#include <SFML/Graphics.hpp>
#include <iostream>

#include "hero.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	window.setFramerateLimit(30);

	Hero hero(0, 0);
	Object obj(100, 100);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		obj.show(&window);
		hero.show(&window);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			hero.move(hero.up);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			hero.move(hero.left);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			hero.move(hero.right);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			hero.move(hero.down);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			if (hero.getDistanceToObj(obj) < 80) {
				std::cout << "Too close\n";
			}
			else {
				std::cout << "Too far\n";
			}
		}

		window.display();
	}
	return 0;
}