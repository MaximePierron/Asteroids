#include "Spaceship.h"
#include "Explosion.h"
#include "Missile.h"
#include <iostream>

Spaceship::Spaceship(Space& p_space, Game& p_game, sf::Color const& color) : SpaceElement{ "ressources/vaisseau.png" }, space{ p_space }, game{ p_game } {
	type = elementType::SPACESHIP;
	sprite.setColor(color);
}

void Spaceship::updateState() {
	accelerating = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	turnLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	turnRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShot.getElapsedTime().asSeconds() > 0.1) {
		space.add(std::make_unique<Missile>(position, sprite.getRotation()));
		lastShot.restart();
	}
}

void Spaceship::update(float time) {
	updateState();
	if (!destroyed) {
		if (accelerating) {
			speed += Vector::createFromAngle(THROTTLE * time, sprite.getRotation());
		};
		speed -= speed * DRAG * time;
		if (turnLeft) {
			angularSpeed = -ANGULAR_SPEED;
		}
		else if (turnRight) {
			angularSpeed = ANGULAR_SPEED;
		}
		else {
			angularSpeed = 0.f;
		}
	}
}

void Spaceship::collide(elementType type) {
	if (type == elementType::ASTEROID) {
		destroyed = true;
		game.end();
		space.add(std::make_unique<Explosion>(position));
	}
};