#include "Entities/Player.hpp"

Player::Player(float x, float y) :
	_sprite(20)
{
	translate(x, y);

	this->_maxVelocity = 5.0f;
	this->_velocity = sf::Vector2f(0.0f, 0.0f);
	this->_del = 10.0f;
	this->_sprite.setFillColor(sf::Color::White);
	//this->_sprite.setScale(sf::Vector2f(100, 100));
}

void Player::translate(float x, float y)
{

	this->_position = sf::Vector2f(x, y);
	this->_sprite.setPosition(this->_position.x, this->_position.y);
}
void Player::move(float x, float y)
{

	/* 	if (std::abs(_velocity.x) > _maxVelocity)
	{
		_velocity.x *= _maxVelocity;
	}

	if (std::abs(_velocity.y) > _maxVelocity)
	{
		_velocity.y = _maxVelocity;
	} */

	this->_velocity.x += x;
	this->_velocity.y += y;
}

void Player::update(float dt __attribute__((unused)))
{
	//translate(this->_position.x + this->_velocity, this->_position.y + 0);

	// inputs
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(-this->_del, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(0.0f, -this->_del);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(this->_del, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(0.0f, this->_del);

	translate(this->_position.x + (this->_velocity.x * dt), this->_position.y + (this->_velocity.y * dt));

	if (_position.x < 0 || _position.x > SCREEN_WIDTH - _sprite.getGlobalBounds().width)
	{
		this->_velocity.x = this->_velocity.x * -1;
	}

	if (_position.y < 0 || _position.y > SCREEN_HEIGHT - _sprite.getGlobalBounds().height)
	{
		this->_velocity.y = this->_velocity.y * -1;
	}
}

void Player::draw(sf::RenderWindow* window)
{
	window->draw(this->_sprite);
}
