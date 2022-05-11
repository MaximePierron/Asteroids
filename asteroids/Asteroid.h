#pragma once
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Space.h"
#include "Game.h"
#include "Coordinates.h"
#include "SpaceElement.h"

class Asteroid : public SpaceElement
{
public:
	explicit Asteroid(Space& p_space, Game& p_game, Asteroid* parent = nullptr);
	virtual void collide(elementType type) override;
private:
	Game& game;
	float size = 0;
	Space& space;
};

