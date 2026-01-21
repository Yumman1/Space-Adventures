// Asteroid3.hpp

// Include guard to prevent multiple inclusions of the header
#ifndef ASTEROID3_H
#define ASTEROID3_H


// Include the base class header
#include "Obstacle.hpp"


// Asteroid3 class inheriting from Obstacle class
class Asteroid3 : public Obstacle {
public:
    Asteroid3(SDL_Renderer* renderer, int x, int y);
    void update() ; // Override the update method from the base class
    // Getters for position
    int getXPosition();
    int getYPosition();
    bool isActive()const; // Check if the asteroid is active
    void destroyasteroid(); // Deactivate the asteroid
    void reset(int x, int y); // Implement the reset function

    
    private:
    bool active;  // Member variable indicating if the asteroid is active or not
};

#endif // ASTEROID3_H
