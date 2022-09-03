#include "Game.hpp"

#include <cassert>

#include "Asteroid.hpp"
#include "Background.hpp"
#include "BattleField.hpp"
#include "FpsCounter.hpp"
#include "GameComponent.hpp"
#include "GamePlaying.hpp"

GameInformation Game::gameInformation{};
GameTexture Game::gameTexture{};
sf::RenderWindow* Game::windowPtr{nullptr};

sf::Time Game::getTimeGame()
{
    return gameInformation.gameClock.getElapsedTime();
}

sf::Vector2i Game::getMousePosition()
{
    return sf::Mouse::getPosition(*windowPtr);
}

GameInformation Game::getGameInformation()
{
    updateGameInformation();
    return gameInformation;
}

void Game::initialize(sf::RenderWindow& window)
{
    
    windowPtr = &window;
    Background::initTexture();
    Asteroid::initTexture();
}

void Game::updateGameInformation()
{
    gameInformation.mousePos = sf::Mouse::getPosition(*windowPtr);
    gameInformation.windowSize = windowPtr->getSize();
}


void verifyInit(sf::RenderWindow* window_ptr)
{
    assert(window_ptr != nullptr && "game initializer was not called ");
}

void Game::run()
{
    verifyInit(windowPtr);

    gameInformation.gameClock.restart();

    std::unique_ptr<GamePlaying> gamePlaying = std::make_unique<GamePlaying>();
    FpsCounter fps;
    
    while (windowPtr->isOpen())
    {
        //fps.printFPS();
        sf::Event event{};
        while (windowPtr->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                windowPtr->close();

        }
        gamePlaying->update();

        windowPtr->clear();
        
        windowPtr->draw(*gamePlaying);

        windowPtr->display();

        if (gamePlaying->end())
        {
            gamePlaying = std::make_unique<GamePlaying>();
        }
        
        
    }
}

/*void Game::earnScore(int scoreEarn)
{
    score+=scoreEarn;
}
*/
