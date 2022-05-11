#pragma once
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include <array>
#include "Coordinates.h"

enum class elementType {SPACESHIP, ASTEROID, MISSILE, OTHER};

class SpaceElement
{
public:
	virtual ~SpaceElement() = default;
	explicit SpaceElement(std::string const& imagePath);
	void refresh(float time);
	virtual void print(sf::RenderWindow& window) const;

	static inline bool isDestroyed(std::unique_ptr<SpaceElement>& element) { return element->destroyed; };

	float getRadius() const;
	void testCollision(SpaceElement& other);
	virtual void collide(elementType type) = 0;
protected:
	virtual void update(float time);
	elementType type{ elementType::OTHER };
	sf::Sprite sprite{};
	Coordinates position{};
	Vector speed{ 0.f, 0.f };
	float angularSpeed{};
	bool destroyed = false;
};

