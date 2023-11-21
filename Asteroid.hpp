// Asteroid.hpp
#ifndef ASTEROID_H
#define ASTEROID_H

#include "Obstacle.hpp"

class Asteroid : public Obstacle {
public:
    Asteroid(SDL_Renderer* renderer, int x, int y);
    void update() ; // Override the update method from the base class
    

};

#endif // ASTEROID_H
