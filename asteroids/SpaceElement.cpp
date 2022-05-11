#include "SpaceElement.h"
#include "RessourceManager.h"
#include <iostream>

SpaceElement::SpaceElement(std::string const& imagePath) {
	sprite.setTexture(RessourceManager<sf::Texture>::getRessource(imagePath));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.getX(), position.getY());
}

void SpaceElement::refresh(float time) {
	update(time);
	auto movement = speed * time;
	position += movement;
	sprite.setPosition(position.getX(), position.getY());
	sprite.rotate(angularSpeed*time);
}

void SpaceElement::update(float time) {};

void SpaceElement::print(sf::RenderWindow& window) const {
	auto prints = std::array<Vector, 9>{Vector{ -1, -1 }, Vector{ 0, -1 }, Vector{ 1, -1 },
		Vector{ -1, 0 }, Vector{ 0, 0 }, Vector{ 1, 0 },
		Vector{ -1, 1 }, Vector{ 0, 1 }, Vector{ 1, 1 }
	};
	for (auto& print : prints) {
		auto transform = sf::Transform{};
		transform.translate(print.x * Coordinates::getSpaceLength(), print.y * Coordinates::getSpaceHeight());
		window.draw(sprite, transform);
	}
}

float SpaceElement::getRadius() const {
	return sprite.getGlobalBounds().height / 2.4f;
}

void SpaceElement::testCollision(SpaceElement& other) {
	auto distance = position.calculateDistance(other.position);
	if (distance < getRadius() + other.getRadius()) {
		collide(other.type);
	}
}