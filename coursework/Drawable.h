#include <SFML/Graphics.hpp>

class Drawable {
protected:
	virtual void show(sf::RenderWindow*) = 0;
};