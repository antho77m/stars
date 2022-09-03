#include "BulletContainer.hpp"


#include "Bullet.hpp"
#include "Game.hpp"
#include "GameComponent.hpp"

void BulletContainer::addBullet(Bullet bullet)
{
	bullets.push_back(bullet);
}

void BulletContainer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto const& bullet : bullets)
	{
		target.draw(bullet);
	}
}

bool bulletNotInScreen(const Bullet& bullet)
{
	const sf::Vector2f screenSize{ Game::getGameInformation().windowSize };
	return ( bullet.getPosition().x  < 0 || bullet.getPosition().y  < 0
		|| bullet.getPosition().x  > screenSize.x || bullet.getPosition().y  > screenSize.y);

}


void BulletContainer::advanceBullets()
{
	for (auto& bullet : bullets)
	{
		bullet.advance();
	}
	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), bulletNotInScreen), bullets.end());
	

}

Bullet* BulletContainer::getBullet(int index)
{
	return &bullets[index];
}

bool BulletContainer::removeBullet(Bullet& bullet)
{
	auto it = std::ranges::find(bullets,bullet);
	
	if (it != bullets.end())
	{
		it->intersected();
		bullets.erase(it);
		return true;
	}
	return false;

}

size_t BulletContainer::getSize() const
{
	return bullets.size();
}
