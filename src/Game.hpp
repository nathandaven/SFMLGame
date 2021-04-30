#include "Engine/StateMachine.hpp"
#include "Global.hpp"
#include "Platform/Platform.hpp"

// causes source files to only be loaded once
#pragma once

/*
	This class wraps the game engine into its own class.
 */

struct GameData
{
	sf::RenderWindow* window;
	Engine::StateMachine machine;
};

typedef std::shared_ptr<GameData> GameDataRef;
class Game
{

private:
	// For platform specific methods
	util::Platform platform;

	// Game Variables
	//sf::RenderWindow* window;
	sf::VideoMode videoMode;
	//sf::Event event;

	// Private Functions
	void initVariables();
	void initWindow();

	// Game Data ref
	GameDataRef _data = std::make_shared<GameData>();

public:
	// Constructors and Destructors
	Game();
	virtual ~Game();

	// Accessors
	bool isRunning() const;

	// Functions
	void updatePollEvents();
	void update();
	void render();
	void run();
};

// custom exception to use for debugging
struct GameException : public std::exception
{
protected:
	const char* errorMsg;

public:
	GameException(const char* str)
	{
		errorMsg = str;
	}
	const char* what() const throw()
	{
		return errorMsg;
	}
};
