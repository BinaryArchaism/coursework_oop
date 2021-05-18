#include <SFML/Graphics.hpp>
#include "Drawable.h"

class Hero : public Drawable {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int x;
	int y;
public:
	Hero(int x, int y);
	void show(sf::RenderWindow* window) override;
};