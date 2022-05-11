#pragma once
#include "SpaceElement.h"
#include <SFML/Audio.hpp>

class Missile :
    public SpaceElement
{
public:
    Missile(Coordinates const& p_position, float rotation);
    virtual void collide(elementType type) override;
private:
    sf::Sound sound{};
    static constexpr float MISSILE_SPEED = 2000.f;
};

