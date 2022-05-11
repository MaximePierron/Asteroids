#include "Asteroid.h"
#include "Vector.h"
#include "Explosion.h"
#include <random>

Asteroid::Asteroid(Space& p_space, Game& p_game, Asteroid* parent) : SpaceElement{ "ressources/asteroide.png" }, space{ p_space }, game{ p_game } {
	type = elementType::ASTEROID;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> distribPosition(-150, 150);
	std::uniform_real_distribution<float> distribSpeed(80, 120);
	std::uniform_real_distribution<float> distribAngle(0, 360);
	std::uniform_real_distribution<float> distribAngularSpeed(10, 30);
	std::uniform_real_distribution<float> distribSize(0.5, 1);
	speed = Vector::createFromAngle(distribSpeed(gen), distribAngle(gen));
	angularSpeed = distribAngularSpeed(gen);
	size = distribSize(gen);
	sprite.setScale(size, size);
	if (parent) {
		sprite.setScale(parent->sprite.getScale().x / 1.4f, parent->sprite.getScale().y / 1.4f);
		position = parent->position;
	}
	else {
		position = { distribPosition(gen), distribPosition(gen) };
	}
}

void Asteroid::collide(elementType type) {
	if (type == elementType::MISSILE) {
		destroyed = true;
		game.addPoints(sprite.getScale().x * 100);
		if (sprite.getScale().x > 0.2) {
			space.add(std::make_unique<Asteroid>(space, game, this));
			space.add(std::make_unique<Asteroid>(space, game, this));
		}
		space.add(std::make_unique<Explosion>(position));
	}
};