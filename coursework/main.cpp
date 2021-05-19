#include <SFML/Graphics.hpp>
#include <iostream>

#include "Hero.h"
#include "Object.h"
#include "Controller.h"
#include "View.h"

class Game {
private:
	Hero hero1;
	//Object obj1;
	sf::RenderWindow* window1;
public:
	Game() {
		hero1 = Hero(0, 0);
	}
	void loop() {
		/*window = &sf::RenderWindow(sf::VideoMode(800, 600), "Test", sf::Style::Close);
		(*window).setFramerateLimit(30);

		hero = Hero(0, 0);
		Object obj(100, 100);
		Controller controller(window, &hero, &obj);
		View view(window, &hero, &obj);

		while ((*window).isOpen())
		{
			controller.pollEvent();

			(*window).clear();

			view.show();

			controller.getInput();

			(*window).display();
		}*/
		sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
		window.setFramerateLimit(30);

		Hero hero(0, 0);
		Object obj(100, 100);
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
	}
};

int main() {
	//Game game();
	//game.loop();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	window.setFramerateLimit(30);

	Hero hero(0, 0);
	Object obj(100, 100);
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