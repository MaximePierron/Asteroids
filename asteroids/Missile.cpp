#include "Missile.h"
#include "RessourceManager.h"

Missile::Missile(Coordinates const& p_position, float rotation) : SpaceElement{ "ressources/missile.png" } {
	type = elementType::MISSILE;
	position = p_position;
	sprite.setRotation(rotation);
	speed = Vector::createFromAngle(MISSILE_SPEED, rotation);
	sound.setBuffer(RessourceManager<sf::SoundBuffer>::getRessource("ressources/laser.wav"));
	sound.play();
}

void Missile::collide(elementType type) {
	if (type != elementType::SPACESHIP) {
		destroyed = true;
	}
};