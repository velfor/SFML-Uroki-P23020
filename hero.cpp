#include "hero.hpp"
#include <iostream>
Hero::Hero() {
	heroimage.loadFromFile("images/hero.png");//загружаем в него файл
	herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)
	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
	herosprite.setTextureRect(sf::IntRect(0, 192, 96, 96));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(50, 25);//задаем начальные координаты появления спрайта
}
sf::Sprite& Hero::getSprite() { return herosprite; }
void Hero::moveLeft(float time, float currentFrame) {
	currentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	if (currentFrame > 3) currentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
	herosprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 96, 96, 96)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
	herosprite.move(-0.2 * time, 0);//происходит само движение персонажа влево
	//herosprite.move(-0.2 * time, 0);
	//herosprite.setTextureRect(sf::IntRect(0, 96, 96, 96));
}
void Hero::moveRight(float time, float& currentFrame) {
	currentFrame += 0.01 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	std::cout << time << ' '<< currentFrame << std::endl;
	if (currentFrame > 3) currentFrame -= 3; //если пришли к третьему кадру - откидываемся назад.
	herosprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 192, 96, 96)); //проходимся по координатам Х. получается 0, 96,96*2 и опять 0
	herosprite.move(0.2 * time, 0);//происходит само движение персонажа вправо
}
void Hero::moveUp(float time, float currentFrame) {
	currentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	if (currentFrame > 3) currentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
	herosprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 288, 96, 96)); //проходимся по координатам Х. получается 0,96,96*2, и опять 0
	herosprite.move(0, -0.2 * time);//происходит само движение персонажа вверх
}
void Hero::moveDown(float time, float currentFrame) {
	currentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	if (currentFrame > 3) currentFrame -= 3; //если пришли к третьему кадру - откидываемся назад.
	herosprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 0, 96, 96)); //проходимся по координатам Х. получается 0,96,96*2,и опять 0
	herosprite.move(0, 0.2 * time);//происходит само движение персонажа вниз
}