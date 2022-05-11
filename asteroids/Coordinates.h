#pragma once
#include "Vector.h"

class Coordinates
{
public:
    static void initiateSpace(int length, int heigth);
    static inline int getSpaceLength() { return spaceLength; };
    static inline int getSpaceHeight() { return spaceHeight; };
    Coordinates();
    Coordinates(float px, float py);

    inline float getX() const { return x; };
    inline float getY() const { return y; };

    void operator+=(Vector const& vecteur);
    float calculateDistance(Coordinates const& autre) const;

private:
    void recalculate();
    float x{ spaceLength / 2.f };
    float y{ spaceHeight / 2.f };

    static int spaceLength;
    static int spaceHeight;
};

