#include <SFML/Graphics.hpp>

class Drawable {
public:
	virtual void show(sf::RenderWindow*) = 0;
};