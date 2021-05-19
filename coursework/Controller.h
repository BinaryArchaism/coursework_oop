#pragma once
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Object.h"
class Controller
{
private:
	bool KeyPressed(sf::Keyboard::Key Key);
	bool KeyReleased(sf::Keyboard::Key Key);
	bool KeyHeld(sf::Keyboard::Key Key);

	bool CurrentKeyState[sf::Keyboard::KeyCount];
	bool PreviousKeyState[sf::Keyboard::KeyCount];
	sf::Event event;
	sf::RenderWindow* window;
	Hero* hero;
	Object* obj;
public:
	Controller(sf::RenderWindow*, Hero*, Object*);
	void pollEvent();
	void getInput();
};

