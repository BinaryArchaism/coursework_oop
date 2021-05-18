#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class hero {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;
    sf::Time start;
    int sprite_count =  4;
    int sprite_x = 16;
    int sprite_y = 16;
    std::string texture_file = "images/grayNinja.png";
    int x = 400;
    int y = 300;
    int currentSprite[4];
    int currentState;
    sf::SoundBuffer buffer;
    sf::Sound step;

public:
    hero();
    void show(sf::RenderWindow* window);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    int getX();
    int getY();
    void nullStates(int currentState);
    void nextSprite(int currentState);
};  