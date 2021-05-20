#include <SFML/Graphics.hpp>
#include <iostream>

#include "hero.h"
#include "Object.h"
#include "Controller.h"
#include "View.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	window.setFramerateLimit(30);

	Hero hero(64, 64);
	Object obj(250, 150);
	Controller controller(&window, &hero, &obj);
	View view(&window, &hero, &obj);

	while (window.isOpen())
	{
		controller.pollEvent();

		window.clear();

		view.show();

		controller.getInput();

		window.display();
	}
	return 0;
}