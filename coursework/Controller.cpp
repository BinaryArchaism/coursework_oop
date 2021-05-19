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

void Controller::getMovementInput()
{
	for (unsigned int i = 0; i < sf::Keyboard::KeyCount; ++i) {
		PreviousKeyState[i] = CurrentKeyState[i];
		CurrentKeyState[i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
	}

	if (KeyPressed(sf::Keyboard::E)) {
		if ((*hero).getDistanceToObj((*obj)) < 80) {
			std::cout << "Too close\n";
		}
		else {
			std::cout << "Too far\n";
		}
	}

	if (KeyHeld(sf::Keyboard::W)) {
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

	/*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
		if ((*hero).getDistanceToObj((*obj)) < 80) {
			std::cout << "Too close\n";
		}
		else {
			std::cout << "Too far\n";
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		(*hero).move((*hero).up);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		(*hero).move((*hero).left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		(*hero).move((*hero).right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		(*hero).move((*hero).down);
	}*/
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