#include "Background.hpp"

#include <iostream>

#include "Game.hpp"
#include "GameComponent.hpp"


void Background::initTexture()
{
	if (!Game::gameTexture.textures.addTexture("starsBackground", "img/starBackground.jpg"))
	{
		std::cout<<"Error loading texture <starsBackground>" <<std::endl;
	}
}

Background::Background(sf::Vector2u size)
{
	texture = Game::gameTexture.textures.getTexture("starsBackground");

	background.setSize(sf::Vector2f(size));
	background.setTexture(texture.get());
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);

}
