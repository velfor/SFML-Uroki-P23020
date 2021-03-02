#include <SFML/Graphics.hpp>
#include "hero.hpp"
using namespace sf;

int main()
{
    //создаем переменную времени, т.о. привязка ко времени
    //(а не загруженности/мощности процессора).
    Clock clock; 
    //дать прошедшее время в микросекундах
    float time = clock.getElapsedTime().asMicroseconds(); 
    clock.restart(); //перезагружает время
    time = time*2; //скорость игры

    float currentFrame = 0;//для анимации

    Hero hero1;

    RenderWindow window(VideoMode(800, 600), "SFML 1 lesson");
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
        //координата Y, на которой герой изображен идущим влево равна 96
        if (Keyboard::isKeyPressed(Keyboard::Left)||
            Keyboard::isKeyPressed(Keyboard::A)) {
            hero1.moveLeft(time, currentFrame);
        }
        //координата Y, на которой герой изображен идущем вправо равна 96+96=192
        if (Keyboard::isKeyPressed(Keyboard::Right) ||
            Keyboard::isKeyPressed(Keyboard::D)) {
            hero1.moveRight(time, currentFrame);
        }
        //координата Y на которой герой изображен идущим вверх равна 288
        if (Keyboard::isKeyPressed(Keyboard::Up) ||
            Keyboard::isKeyPressed(Keyboard::W)) {
            hero1.moveUp(time, currentFrame);
        }
        //координата 0, это верхняя часть изображения с героем, от нее и отталкиваемся ровными квадратиками по 96. 
        if (Keyboard::isKeyPressed(Keyboard::Down) ||
            Keyboard::isKeyPressed(Keyboard::S)) {
            hero1.moveDown(time, currentFrame);
        }
        window.clear();
        window.draw(hero1.getSprite());//выводим спрайт
        window.display();
    }
    return 0;
}