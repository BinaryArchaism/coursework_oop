#include <SFML/Graphics.hpp>
#include <iostream>

#include "aTank.h"
#include "redTank.h"

//TODO class Game

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	window.setFramerateLimit(30);

	redTank tank(100, 100, &window);

	while (window.isOpen())
	{
		

		window.clear();

		

		

		window.display();
	}
	return 0;
}