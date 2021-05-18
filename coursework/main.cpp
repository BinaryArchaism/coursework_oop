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

		window.display();
	}
	return 0;
}