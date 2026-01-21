// Asteroid2.hpp


// Include guard to prevent multiple inclusions of the header
#ifndef ASTEROID2_H
#define ASTEROID2_H


#include "Obstacle.hpp" // Include the base class header



// Asteroid class inheriting from Obstacle class
class Asteroid2 : public Obstacle {
public:

    // Constructor for Asteroid class
    Asteroid2(SDL_Renderer* renderer, int x, int y);
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

#endif // ASTEROID2_H
