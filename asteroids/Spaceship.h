#pragma once
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Coordinates.h"
#include "SpaceElement.h"
#include "Explosion.h"
#include "Space.h"
#include "Game.h"

class Spaceship : public SpaceElement
{
public:
	explicit Spaceship(Space& p_space, Game& p_game, sf::Color const& color);
	virtual void collide(elementType type) override;

protected:
	virtual void update(float time) override;

private:
	void updateState();
	bool accelerating = false;
	bool turnLeft = false;
	bool turnRight = false;

	Game& game;
	Space& space;
	sf::Clock lastShot{};

	static constexpr float THROTTLE = 800.f;
	static constexpr float DRAG = 2.f;
	static constexpr float ANGULAR_SPEED = 400.f;

};

