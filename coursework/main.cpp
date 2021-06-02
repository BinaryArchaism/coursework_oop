#include <SFML/Graphics.hpp>
#include <iostream>

#include "aTank.h"
#include "redTank.h"

//TODO class Game

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	window.setFramerateLimit(30);

	redTank tank(0, 0);

	sf::Texture tx;
	tx.loadFromFile("assets/redTank.png");
	sf::Sprite sp;
	sp.setTexture(tx);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		tank.show(&window);
		//window.draw(sp);
		window.display();
	}
	return 0;
}