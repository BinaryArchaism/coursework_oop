#include <SFML/Graphics.hpp>

#include "hero.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	Hero hero(0, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

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

		window.display();
	}
	return 0;
}