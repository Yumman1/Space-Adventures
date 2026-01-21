// Asteroid.hpp


// Include guard to prevent multiple inclusions of the header
#ifndef ASTEROID_H
#define ASTEROID_H


// Include the base class header
#include "Obstacle.hpp"



// Asteroid class inheriting from Obstacle class
class Asteroid : public Obstacle {
public:

    // Constructor for Asteroid class
    Asteroid(SDL_Renderer* renderer, int x, int y);
    void update() ; // Override the update method from the base class
    // Getters for position
    int getXPosition();
    int getYPosition();
    bool isActive()const; // Check if the asteroid is active
    void destroyasteroid(); // Deactivate the asteroid
    void reset(int x, int y); // Implement the reset function

   
    private:
    bool active; // Member variable indicating if the asteroid is active or not
};

#endif // ASTEROID_H
