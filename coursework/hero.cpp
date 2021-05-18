#include <iostream>
#include <SFML/Graphics.hpp>
#include "hero.h"

hero::hero() {
    texture.loadFromFile(texture_file);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, sprite_x, sprite_y));
    sprite.scale(2, 2);
    currentState = 0;
    start = clock.getElapsedTime();
    for (int i = 0; i < sprite_count; ++i)
        currentSprite[i] = 0;
    buffer.loadFromFile("images/step.wav");
    step.setBuffer(buffer);
    step.setVolume(25);
    step.setPitch(0.15f);
}

void hero::show(sf::RenderWindow* window) {
    sprite.setPosition(x-sprite_x, y-sprite_y);
    (*window).draw(sprite);
    if (clock.getElapsedTime().asMilliseconds() - start.asMilliseconds() > 200) {
        sprite.setTextureRect(sf::IntRect(currentState * sprite_x, currentSprite[currentState] * sprite_y, sprite_x, sprite_y));
        for (int i = 0; i < sprite_count; i++)
            nullStates(i);
    }
}

void hero::moveRight() {
    x += 2;
    currentState = 3;
    sprite.setTextureRect(sf::IntRect(3 * sprite_x, currentSprite[3] * sprite_y, sprite_x, sprite_y));
    if (clock.getElapsedTime().asMilliseconds() - start.asMilliseconds() > 180) {
        nextSprite(3);
        step.play();
        start = clock.getElapsedTime();
    }
    nullStates(3);
}

void hero::moveLeft() {
    x -= 2;
    currentState = 2;
    sprite.setTextureRect(sf::IntRect(2 * sprite_x, currentSprite[2] * sprite_y, sprite_x, sprite_y));
    if (clock.getElapsedTime().asMilliseconds() - start.asMilliseconds() > 180) {
        nextSprite(2);
        step.play();
        start = clock.getElapsedTime();
    }
    nullStates(2);
}

void hero::moveUp() {
    y -= 2;
    currentState = 1;
    sprite.setTextureRect(sf::IntRect(1 * sprite_x, currentSprite[1] * sprite_y, sprite_x, sprite_y));
    if (clock.getElapsedTime().asMilliseconds() - start.asMilliseconds() > 180) {
        nextSprite(1);
        step.play();
        start = clock.getElapsedTime();
    }
    nullStates(1);
}

void hero::moveDown() {
    y += 2;
    currentState = 0;
    sprite.setTextureRect(sf::IntRect(0 * sprite_x, currentSprite[0] * sprite_y, sprite_x, sprite_y));
    if (clock.getElapsedTime().asMilliseconds() - start.asMilliseconds() > 180) {
        nextSprite(0);
        step.play();
        start = clock.getElapsedTime();
    }
    nullStates(0);
}

int hero::getX() {
    return x;
}

int hero::getY() {
    return y;
}

void hero::nullStates(int currentState) {
    for (int i = 0; i < sprite_count; ++i)
        if (i != currentState)
            currentSprite[i] = 0;
}

void hero::nextSprite(int currentState) {
    if (currentSprite[currentState] == 3)
        currentSprite[currentState] = 0;
    else
        currentSprite[currentState] += 1;
}
