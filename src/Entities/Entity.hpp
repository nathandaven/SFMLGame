#pragma once

namespace Engine
{
class Entity
{
private:
	sf::Vector2f _position;
	float _del;

	// temporary
	sf::CircleShape _sprite;

public:
	Entity(float x, float y)
	{
	}
	~Entity()
	{
	}

	virtual void translate(float x, float y) = 0;
	virtual void move(float x, float y) = 0;
	virtual void update(float dt __attribute__((unused))) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
};
}