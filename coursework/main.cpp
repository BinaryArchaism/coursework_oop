#include <SFML/Graphics.hpp>
#include <iostream>

#include "hero.h"
#include "Object.h"
#include "Controller.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	window.setFramerateLimit(30);

	Hero hero(0, 0);
	Object obj(100, 100);
	Controller controller(&window, &hero, &obj);

	while (window.isOpen())
	{
		controller.pollEvent();
		window.clear();
		obj.show(&window);
		hero.show(&window);
		controller.getMovementInput();
		window.display();
	}
	return 0;
}