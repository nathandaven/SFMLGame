#pragma once

#include "Entities/Player.hpp"
#include "Game.hpp"
#include "Global.hpp"
#include "States/State.hpp"

class GameState : public Engine::State
{
public:
	GameState(GameDataRef data);
	//~MainMenuState() = default;

	void initState();
	void updateInputs();
	void updateState(float dt __attribute__((unused)));
	void drawState(float dt __attribute__((unused)));

private:
	GameDataRef _data;
	Player _player;
};
