#include "Game.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "RessourceManager.h"
#include "font.h"
#include <memory>
#include <string>
#include <fstream>

using namespace std::string_literals;

const sf::Color SPACESHIP_COLOR = sf::Color{ 128,255,128 };

Game::Game(Space& p_space) : space{ p_space } {
    if (!font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) throw std::runtime_error{ "Font not found!" };
    scoreText.setFont(font);
    scoreText.move(0, 30);
    bestScoreText.setFont(font);
    auto scoreFile = std::ifstream{ "bestScore.txt" };
    if (scoreFile.is_open()) {
        scoreFile >> bestScore;
    }
    scoreFile.close();
    updateBestScore();
    try {
        welcomeSprite.setTexture(RessourceManager<sf::Texture>::getRessource("ressources/accueil.png"));
    }
    catch (std::exception const& exception) {
        initException(exception);
    }
    
}

void Game::start() {
	playing = true;
    score = 0;
    updateScore();
    space.add(std::make_unique<Spaceship>(space, *this, SPACESHIP_COLOR));
    space.add(std::make_unique<Asteroid>(space, *this));
    space.add(std::make_unique<Asteroid>(space, *this));
    space.add(std::make_unique<Asteroid>(space, *this));
    space.add(std::make_unique<Asteroid>(space, *this));
}

void Game::end() {
    playing = false;
    if (score > bestScore) {
        bestScore = score;
        updateBestScore();
        auto scoreFile = std::ofstream{"bestScore.txt"};
        if (scoreFile.is_open()) {
            scoreFile << bestScore;
        }
        else {
            throw std::runtime_error{ "Impossible to open bestScore.txt" };
        }
        scoreFile.close();
    }
    space.empty();
}

void Game::addPoints(int points) {
    score += points;
    updateScore();
}

void Game::updateScore() {
    scoreText.setString("Score: "s + std::to_string(score));
}

void Game::updateBestScore() {
    bestScoreText.setString("Best score: "s + std::to_string(bestScore));
}

void Game::print(sf::RenderWindow& window) const {
    if (textException) {
        window.draw(*textException);
    }
    else {
        if (!playing && space.isEmpty()) {
            window.draw(welcomeSprite);
        }
        else {
            window.draw(scoreText);
        }
        window.draw(bestScoreText);
    }


}

void Game::initException(std::exception const& exception) {
    textException = std::make_unique<sf::Text>();
    textException->setFont(font);
    textException->setString(exception.what());
    textException->setFillColor(sf::Color::Red);
}
