#include <SFML/Graphics.hpp>

<<<<<<< HEAD
#include "hero.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Close);
	Hero hero(0, 0);
=======
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
>>>>>>> 30842d5d5fb981c6402439002ca2117279af395a

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
<<<<<<< HEAD
		window.clear();

		hero.show(&window);

		window.display();
	}
=======

		window.clear();
		window.draw(shape);
		window.display();
	}

>>>>>>> 30842d5d5fb981c6402439002ca2117279af395a
	return 0;
}