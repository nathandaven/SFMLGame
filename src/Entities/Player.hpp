
#pragma once

#include "Global.hpp"

class Player
{
private:
	sf::Vector2f _position;
	sf::Vector2f _velocity;
	float _maxVelocity;
	float _del;

	// temporary
	sf::CircleShape _sprite;

public:
	Player(float x, float y);
	//~Player();

	void translate(float x, float y);
	void move(float x, float y);
	void update(float dt);
	void draw(sf::RenderWindow* window);
};