#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

struct GameInformation;
struct GameTexture;

class Game
{

public:


	static GameTexture gameTexture;

	static sf::Time getTimeGame();
	static sf::Vector2i getMousePosition();
	static GameInformation getGameInformation();

	static void initialize(sf::RenderWindow& window);
	static void run();
	
private:
	static void updateGameInformation();
	static GameInformation gameInformation;

	
	static sf::RenderWindow* windowPtr;

};


