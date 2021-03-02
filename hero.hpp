#pragma once
#include <SFML/Graphics.hpp>
class Hero {
private:
    sf::Image heroimage; //������� ������ Image (�����������)
    sf::Texture herotexture;//������� ������ Texture (��������)
    sf::Sprite herosprite;//������� ������ Sprite(������)
public:
    Hero();
    sf::Sprite& getSprite();
    void moveLeft(float, float);
    void moveRight(float, float&);
    void moveUp(float, float);
    void moveDown(float, float);
};


