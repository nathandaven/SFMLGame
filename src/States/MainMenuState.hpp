#pragma once

#include "Game.hpp"
#include "Global.hpp"
#include "States/State.hpp"

class MainMenuState : public Engine::State
{
public:
	MainMenuState(GameDataRef data);
	//~MainMenuState() = default;

	void initState();
	void updateInputs();
	void updateState(float dt);
	void drawState(float dt);

private:
	GameDataRef _data;
};
