#pragma once
#include "Background.hpp"
#include "GamePart.hpp"
#include "BattleField.hpp"

class GamePlaying : public GamePart
{
public:
	GamePlaying();

	void update() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool end();


private:
	BattleField battleField;
	Background background;
};

