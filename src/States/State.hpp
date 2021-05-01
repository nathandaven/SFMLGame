#pragma once

namespace Engine
{
class State
{
public:
	// SHOULD BE VIRTUAL
	State()
	{}
	virtual ~State()
	{}

	virtual void initState() = 0;
	virtual void updateInputs() = 0;
	virtual void updateState(float dt __attribute__((unused))) = 0;
	virtual void drawState(float dt __attribute__((unused))) = 0;
	virtual void pauseState()
	{}
	virtual void resumeState()
	{}

	sf::Event event;
};
}