#include <SFML/Graphics.hpp>
#include <iostream>

#include "hero.h"
#include "Object.h"
#include "Controller.h"
#include "View.h"
#include "Wall.h"
#include "Wall2.h"

//TODO class Game

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	window.setFramerateLimit(30);

	Hero hero(64, 64);
	Wall obj(250, 150);
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

//class Game {
//private:
//	Hero hero;
//	Wall wall;
//public:
//	void gameLoop() {
//		sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
//		window.setFramerateLimit(30);
//
//		hero = Hero(64, 64);
//		wall = Wall(250, 150);
//
//		Controller controller(&window, &hero, &wall);
//		View view(&window, &hero, &wall);
//
//		while (window.isOpen())
//		{
//			controller.pollEvent();
//
//			window.clear();
//
//			view.show();
//
//			controller.getInput();
//
//			window.display();
//		}
//	}
//};
//
//int main() {
//	Game game();
//	game.gameLoop();
//}