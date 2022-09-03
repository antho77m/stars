#include "GamePlaying.hpp"

#include <iostream>

#include "Game.hpp"
#include "GameComponent.hpp"

GamePlaying::GamePlaying():GamePart(),background(Game::getGameInformation().windowSize),battleField()
{
}

void GamePlaying::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(battleField);
	
}

bool GamePlaying::end()
{
	return battleField.shipIsDie(Game::getGameInformation().windowSize);
}

void GamePlaying::update()
{
	battleField.updateField(Game::getMousePosition());
}
