#pragma once
#include <vector>
#include <SFML/Graphics/Drawable.hpp>

#include "Bullet.hpp"


class BulletContainer:public sf::Drawable
{
public:
	BulletContainer() = default;
	void addBullet(Bullet bullet);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void advanceBullets();
	Bullet* getBullet(int index);
	bool removeBullet(Bullet& bullet);
	size_t getSize() const;
private:
	std::vector<Bullet> bullets;
};

