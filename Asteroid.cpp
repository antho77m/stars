#include "Asteroid.hpp"

#include <iostream>

#include "AngleRadiant.hpp"
#include "Game.hpp"
#include "GameComponent.hpp"



void Asteroid::initTexture()
{
	if(!Game::gameTexture.textures.addTexture("asteroid", "img/asteroid.png"))
	{
		std::cout<<"Error loading texture <asteroid.png>"<<std::endl;
	}
	
}


Asteroid::Asteroid(sf::Vector2f position, float speed, float angleDirection, float rotation, Size size):asteroid(*Game::gameTexture.textures.getTexture("asteroid")),speed(speed), rotation(rotation), angleDirection(angleDirection),life(size),size(size)
{
	asteroid.setPosition(position);

	float sizeScale = (0.75 + static_cast<float>(size) * 0.25f) /2.f;
	asteroid.setScale(sizeScale, sizeScale);
	asteroid.setOrigin(asteroid.getGlobalBounds().width / 2, asteroid.getGlobalBounds().height / 2);
}

void Asteroid::advance()
{
	if (lastUpdate.asSeconds() != 0)
	{
		sf::Time delta{ Game::getTimeGame() - lastUpdate };
		sf::Vector2f translation{ speed * cos(angleDirection), speed * sin(angleDirection) };

		asteroid.move(translation * delta.asSeconds());
		asteroid.rotate(rotation * delta.asSeconds());

	}
	
	lastUpdate = Game::getTimeGame();


}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(asteroid);
}

bool Asteroid::intersects(sf::FloatRect other)const
{
	return asteroid.getGlobalBounds().intersects(other);
}

void Asteroid::intersected()
{
	life--;
}

bool Asteroid::isDestroy()const
{
	return life==0;
}

std::vector<Asteroid> Asteroid::destroy() const
{
	std::vector<Asteroid> newAsteroids;
	//Game::gameInformation.score += static_cast<int>(size)*500;
	int newSize{ size - 1 };
	if (newSize==0)
	{
		return newAsteroids;
	}

	float angle[2] = { 15,-15 };
	for (int i = 0; i < 2; ++i)
	{
		Asteroid newAsteroid {asteroid.getPosition(), speed+50.f/newSize,  angleDirection + convertToRadiant( angle[i]), rotation*3.f, static_cast<Size>(newSize) };
		newAsteroids.push_back(newAsteroid);
	}
	return newAsteroids;
}



sf::FloatRect Asteroid::getGlobalBound() const
{
	return asteroid.getGlobalBounds();
}



