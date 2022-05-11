#include "Space.h"

Space::Space() {

}

void Space::add(std::unique_ptr<SpaceElement> element) {
	toBeAdded.push_back(std::move(element));
}

void Space::refresh() {
    auto loopTime = chrono.restart().asSeconds();
    for (auto i{ 0 }; i < elements.size(); i++) {
        elements[i]->refresh(loopTime);
    }
}

void Space::handleCollision() {
    for (auto i{ 0u }; i<elements.size(); i++) {
        for (auto j{ 0u }; j < elements.size(); j++) {
            if (i != j) {
                elements[i]->testCollision(*elements[j]);
            }
        }
    }
}

void Space::print(sf::RenderWindow& window) const {
    for (auto& element : elements) {
        element->print(window);
    }
}

void Space::clean() {
    if (toBeEmptied) {
        elements.clear();
        toBeEmptied = false;
    }
    auto vectorEnd = std::remove_if(std::begin(elements), std::end(elements), SpaceElement::isDestroyed);
    elements.erase(vectorEnd, std::end(elements));
    for (auto& element : toBeAdded) {
        elements.push_back(std::move(element));
    }
    toBeAdded.clear();
}

void Space::empty() {
    toBeEmptied = true;
}