#include "Entities/Player.hpp"

Player::Player(int x, int y) :
	_sprite(20)
{
	translate(x, y);

	this->_sprite.setFillColor(sf::Color::White);
	//this->_sprite.setScale(sf::Vector2f(100, 100));
}

void Player::translate(int x, int y)
{
	this->_position = sf::Vector2i(x, y);
	this->_sprite.setPosition(this->_position.x, this->_position.y);
}
void Player::moveUp()
{
	translate(this->_position.x + 0, this->_position.y - 5);
}
void Player::moveDown()
{
	translate(this->_position.x + 0, this->_position.y + 5);
}
void Player::moveLeft()
{
	translate(this->_position.x - 5, this->_position.y + 0);
}
void Player::moveRight()
{
	translate(this->_position.x + 5, this->_position.y + 0);
}

void Player::draw(sf::RenderWindow* window)
{
	window->draw(this->_sprite);
}
