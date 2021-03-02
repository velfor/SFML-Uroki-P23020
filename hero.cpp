#include "hero.hpp"
#include <iostream>
Hero::Hero() {
	heroimage.loadFromFile("images/hero.png");//��������� � ���� ����
	herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)
	herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
	herosprite.setTextureRect(sf::IntRect(0, 192, 96, 96));//�������� ������ ��� ������������� � �����
	herosprite.setPosition(50, 25);//������ ��������� ���������� ��������� �������
}
sf::Sprite& Hero::getSprite() { return herosprite; }
void Hero::moveLeft(float time, float currentFrame) {
	currentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
	if (currentFrame > 3) currentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
	herosprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 96, 96, 96)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
	herosprite.move(-0.2 * time, 0);//���������� ���� �������� ��������� �����
	//herosprite.move(-0.2 * time, 0);
	//herosprite.setTextureRect(sf::IntRect(0, 96, 96, 96));
}
void Hero::moveRight(float time, float& currentFrame) {
	currentFrame += 0.01 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
	std::cout << time << ' '<< currentFrame << std::endl;
	if (currentFrame > 3) currentFrame -= 3; //���� ������ � �������� ����� - ������������ �����.
	herosprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 192, 96, 96)); //���������� �� ����������� �. ���������� 0, 96,96*2 � ����� 0
	herosprite.move(0.2 * time, 0);//���������� ���� �������� ��������� ������
}
void Hero::moveUp(float time, float currentFrame) {
	currentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
	if (currentFrame > 3) currentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
	herosprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 288, 96, 96)); //���������� �� ����������� �. ���������� 0,96,96*2, � ����� 0
	herosprite.move(0, -0.2 * time);//���������� ���� �������� ��������� �����
}
void Hero::moveDown(float time, float currentFrame) {
	currentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
	if (currentFrame > 3) currentFrame -= 3; //���� ������ � �������� ����� - ������������ �����.
	herosprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 0, 96, 96)); //���������� �� ����������� �. ���������� 0,96,96*2,� ����� 0
	herosprite.move(0, 0.2 * time);//���������� ���� �������� ��������� ����
}