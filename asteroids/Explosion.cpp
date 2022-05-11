#include "Explosion.h"
#include "RessourceManager.h"

Explosion::Explosion(Coordinates const& p_position) : SpaceElement{ "ressources/explosion.png" } {
	position = p_position;
	sound.setBuffer(RessourceManager<sf::SoundBuffer>::getRessource("ressources/explosion.wav"));
	sound.play();
}

void Explosion::update(float time) {
	duration += time;
	if (duration <= LIFE_SPAN) {
		sprite.setScale(duration / LIFE_SPAN, duration / LIFE_SPAN);
	}
	else {
		sprite.setScale(0, 0);
		if (sound.getStatus() == sf::SoundSource::Stopped) {
			destroyed = true;
		}
	}
};

void Explosion::collide(elementType type) {

}