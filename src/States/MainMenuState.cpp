#include "States/MainMenuState.hpp"
#include "Engine/StateMachine.hpp"
#include "States/GameState.hpp"

MainMenuState::MainMenuState(GameDataRef data) :
	_data(data)
{
}

void MainMenuState::initState()
{
}

void MainMenuState::updateInputs()
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
				if (this->event.key.code == sf::Keyboard::Escape)
					this->_data->window->close();
				if (this->event.key.code == sf::Keyboard::Enter)
					this->_data->states.addState(Engine::StateRef(new GameState(this->_data)), false);
				break;
			default:
				break;
		}
	}
}

// marks dt to not warn compiler
void MainMenuState::updateState(float dt __attribute__((unused)))
{
}

// marks dt to not warn compiler
void MainMenuState::drawState(float dt __attribute__((unused)))
{
	// just for fun, heres hello world text
	// SAMPLE RENDER CODE:

	// background color
	this->_data->window->clear(sf::Color::Black);

	// write text
	sf::Text title;
	sf::Font font;

	// throws error if cant load font
	if (!font.loadFromFile("Content/joystix.ttf"))
	{
		// error...
		throw GameException("yeah");
	}

	// select the font
	title.setFont(font); // font is a sf::Font

	// set the string to display
	title.setString("Epic 2D Game!");

	// set the character size
	title.setCharacterSize(24); // in pixels, not points!

	// set the color
	title.setFillColor(sf::Color::White);

	// set the text style
	title.setStyle(sf::Text::Bold | sf::Text::Underlined);

	title.setPosition(
		(this->_data->window->getSize().x / 2) - (title.getLocalBounds().width / 2),
		(this->_data->window->getSize().y / 2) - (title.getLocalBounds().height / 2));

	// inside the main loop, between window.clear() and window.display()
	this->_data->window->draw(title);

	// END SAMPLE RENDER CODE

	// Displays rendered obejcts
	this->_data->window->display();
}