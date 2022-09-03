#pragma once
#include <SFML/System.hpp>

#include "TextureLoader.hpp"


struct GameInformation
{
	sf::Vector2i mousePos;
	sf::Vector2u windowSize;
	sf::Clock gameClock;

};

struct GameTexture
{
	TextureLoader textures{};
};

