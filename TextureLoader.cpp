#include "TextureLoader.hpp"
#include <SFML/Graphics.hpp>

//return true if the texture is add else false
bool TextureLoader::addTexture(std::string name, std::string path)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path))
	{
		return false;
	}
	textures.insert({ name, std::make_shared<sf::Texture>(texture) });
	
	return true;
}

std::shared_ptr<sf::Texture> TextureLoader::getTexture(std::string name)
{
	if (!textures.contains(name))
	{
		return nullptr;
	}
	return textures.at(name);
}

//return true if the Texture is removed
bool TextureLoader::removeTexture(std::string name)
{

	if ( textures.contains(name) && textures.at(name).use_count() == 1)
	{
		textures.erase(name);
		return true;
	}
	return false;
}



