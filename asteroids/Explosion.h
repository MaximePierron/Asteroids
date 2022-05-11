#pragma once
#include "SpaceElement.h"
#include "Coordinates.h"
#include <SFML/Audio.hpp>

class Explosion :
    public SpaceElement
{
public:
    Explosion(Coordinates const& p_position);
    virtual void collide(elementType type) override;

protected:
    virtual void update(float time) override;

private:
    sf::Sound sound{};
    float duration = 0;
    static constexpr float LIFE_SPAN = 0.1f;
};

