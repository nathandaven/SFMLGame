#include "States/GameState.hpp"
#include "Engine/StateMachine.hpp"

GameState::GameState(GameDataRef data) :
	_data(data),
	_player(200, 200)
{
}

void GameState::initState()
{
}

void GameState::updateInputs()
{
	// Event Polling
	while (this->_data->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
			case sf::Event::Closed:
				this->_data->window->close();
				break;
			case sf::Event::KeyPressed:
				// closing
				if (this->event.key.code == sf::Keyboard::Escape)
					this->_data->window->close();
			default:
				break;
		}
	}
}

// marks dt to not warn compiler
void GameState::updateState(float dt __attribute__((unused)))
{

	this->_player.update(dt);
}

// marks dt to not warn compiler
void GameState::drawState(float dt __attribute__((unused)))
{
	// background color
	this->_data->window->clear(sf::Color::Black);

	// drawing the player sprite
	this->_player.draw(this->_data->window);

	// Displays rendered obejcts
	this->_data->window->display();
}