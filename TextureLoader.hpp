#pragma once

#include <map>
#include <memory>
#include <string>


namespace sf
{
	class Texture;
}
//utiliser shared ptr
class TextureLoader
{
public:
	bool addTexture(std::string name, std::string path);
	std::shared_ptr<sf::Texture> getTexture(std::string name);
	bool removeTexture(std::string name);


private:
	std::map<std::string,std::shared_ptr<sf::Texture>>textures{};


};

