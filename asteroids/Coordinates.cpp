#include "Coordinates.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int Coordinates::spaceLength{ 0 };
int Coordinates::spaceHeight{ 0 };

Coordinates::Coordinates() {
    if (spaceLength == 0 || spaceHeight == 0) {
        std::cerr << "Warning : coordinates created before initialisation !" << std::endl;
    }
}

Coordinates::Coordinates(float px, float py) : x(px), y(py) {
    recalculate();
}

void Coordinates::operator+=(Vector const& vector) {
    x += vector.x;
    y += vector.y;
    recalculate();
}

void Coordinates::initiateSpace(int length, int height) {
    if (spaceLength != 0 || spaceHeight != 0) {
        std::cerr << "Warning : space already initialised !" << std::endl;
    }
    spaceLength = length;
    spaceHeight = height;
}

void Coordinates::recalculate() {
    while (x > spaceLength) {
        x -= spaceLength;
    }
    while (x < 0) {
        x += spaceLength;
    }
    while (y > spaceHeight) {
        y -= spaceHeight;
    }
    while (y < 0) {
        y += spaceHeight;
    }
}

float Coordinates::calculateDistance(Coordinates const& other) const {
    auto delta = Vector{ std::min({abs(x - other.x), abs(x - other.x - spaceLength), abs(x - other.x + spaceLength)}), std::min({abs(y - other.y), abs(y - other.y - spaceHeight), abs(y - other.y + spaceHeight)}) };
    return sqrt(delta.x * delta.x + delta.y * delta.y);
}