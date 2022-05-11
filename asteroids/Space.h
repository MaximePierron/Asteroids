#pragma once
#include "SpaceElement.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>

class Space
{
public:
	Space();
	void add(std::unique_ptr<SpaceElement> element);
	void refresh();
	void handleCollision();
	void print(sf::RenderWindow& window) const;
	void clean();
	void empty();
	inline bool isEmpty() const { return elements.empty() && toBeAdded.empty(); }

private:
	bool toBeEmptied{ false };
	std::vector<std::unique_ptr<SpaceElement>> elements{};
	std::vector<std::unique_ptr<SpaceElement>> toBeAdded{};
	sf::Clock chrono{};
};

