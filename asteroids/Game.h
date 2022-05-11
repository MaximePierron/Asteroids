#pragma once
#include "Space.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include <exception>

class Game
{
public:
	Game(Space& p_space);
	void start();
	void end();
	void addPoints(int points);
	inline bool isPlaying() const { return playing; };
	void print(sf::RenderWindow& window) const;
	void initException(std::exception const& exception);
private:
	int score{};
	int bestScore{};
	void updateScore();
	void updateBestScore();
	Space& space;
	bool playing{ false };
	sf::Text scoreText{};
	sf::Text bestScoreText{};
	sf::Sprite welcomeSprite{};
	sf::Font font{};
	std::unique_ptr<sf::Text> textException{ nullptr };
};

