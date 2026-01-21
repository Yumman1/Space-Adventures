// Asteroid4.hpp
#ifndef ASTEROID4_H
#define ASTEROID4_H

#include "Obstacle.hpp"

class Asteroid4 : public Obstacle {
public:
    Asteroid4(SDL_Renderer* renderer, int x, int y);
    void update() ; // Override the update method from the base class
    // Getters for position
    int getXPosition();
    int getYPosition();
    bool isActive()const;
    void destroyasteroid(); // New function to deactivate the coin
     void reset(int x, int y); // Implement the reset function

    // Constants for width and height
    static constexpr int ASTEROID_WIDTH = 75; // Assuming width
    static constexpr int ASTEROID_HEIGHT = 75; // Assuming height

    private:
    bool active; // Add this member variable
};

#endif // ASTEROID4_H
