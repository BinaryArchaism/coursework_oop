#include "Controller.h"
#include <iostream>

Controller::Controller(sf::RenderWindow* window, Hero* hero, Object* obj) {
	this->window = window;
	this->hero = hero;
	this->obj = obj;
	memset(CurrentKeyState, false, sizeof(CurrentKeyState));
	memset(PreviousKeyState, false, sizeof(PreviousKeyState));
}

void Controller::pollEvent()
{
	while ((*window).pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			(*window).close();
	}
}

void Controller::getInput()
{
	for (unsigned int i = 0; i < sf::Keyboard::KeyCount; ++i) {
		PreviousKeyState[i] = CurrentKeyState[i];
		CurrentKeyState[i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
	}

	if (KeyPressed(sf::Keyboard::C)) {
		std::cout << "Collision: " << (*hero).checkCollison((*obj)) << "\n";
	}

	if (KeyPressed(sf::Keyboard::E)) {
		if ((*hero).getDistanceToObj((*obj)) < 64) {
			(*obj).react();
			std::cout << "Reaction: obj moved\n";
		}
		else {
			std::cout << "Too far\n";
		}
	}

	if (KeyHeld(sf::Keyboard::W)) {
		if (!(*hero).checkCollison((*obj)))
			(*hero).move((*hero).up);
	}
	if (KeyHeld(sf::Keyboard::A)) {
		(*hero).move((*hero).left);
	}
	if (KeyHeld(sf::Keyboard::D)) {
		(*hero).move((*hero).right);
	}
	if (KeyHeld(sf::Keyboard::S)) {
		(*hero).move((*hero).down);
	}
}

bool Controller::KeyPressed(sf::Keyboard::Key Key)
{
	return (CurrentKeyState[Key] && !PreviousKeyState[Key]);
}

bool Controller::KeyReleased(sf::Keyboard::Key Key)
{
	return (!CurrentKeyState[Key] && PreviousKeyState[Key]);
}

bool Controller::KeyHeld(sf::Keyboard::Key Key)
{
	return CurrentKeyState[Key];
}