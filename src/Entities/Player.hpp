
#pragma once

class Player
{
private:
	sf::Vector2i _position;

	// temporary
	sf::CircleShape _sprite;

public:
	Player(int x, int y);
	//~Player();

	void translate(int x, int y);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void draw(sf::RenderWindow* window);
};