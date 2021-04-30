#include "Game.hpp"
#include "Engine/StateMachine.hpp"
#include "States/MainMenuState.hpp"

/*
	This Game object holds all of the primary game code and keeps it out of main.
	(based on: https://youtu.be/kxb0GvBNOGU)
	This also incorporates the cross-platform boilerplate created by Andrew King
	(found here: https://github.com/andrew-r-king/sfml-vscode-boilerplate)
 */

// private
void Game::initVariables()
{
	this->_data->window = nullptr;
	this->_data->machine.addState(Engine::StateRef(new MainMenuState(this->_data)), false);
}
void Game::initWindow()
{
	// creating our window object
	this->_data->window = new sf::RenderWindow();

	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(this->_data->window->getSystemHandle());

	// Use the screenScalingFactor to create video mode and set screen size - 720p by default
	this->videoMode.height = SCREEN_HEIGHT * screenScalingFactor;
	this->videoMode.width = SCREEN_WIDTH * screenScalingFactor;

	// creating our window view using the video mode and disabling resizablilty
	this->_data->window->create(this->videoMode, "Test Game 1", sf::Style::Titlebar | sf::Style::Close);
	platform.setIcon(this->_data->window->getSystemHandle());

	// sets FPS vsync
	this->_data->window->setFramerateLimit(60);
}

// Constructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->run();
}

Game::~Game()
{
	delete this->_data->window;
}

// Accessors
bool Game::isRunning() const
{
	return this->_data->window->isOpen();
}

// Functions
void Game::updatePollEvents()
{
}

void Game::update()
{
	this->updatePollEvents();
}

/*
@return null
renders all game objects on screen (clear -> render -> display)
 */
void Game::render()
{
	// testing states
}

void Game::run()
{
	// initializing a new Game

	// Game Loop
	while (this->isRunning())
	{

		// Update
		//this->update();

		// Render
		//this->render();

		// state machine
		this->_data->machine.processStates();
		this->_data->machine.getActiveState()->updateInputs();
		this->_data->machine.getActiveState()->updateState(0);
		this->_data->machine.getActiveState()->drawState(0);
	}
}
