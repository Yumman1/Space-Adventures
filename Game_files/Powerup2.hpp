// PowerUp2.hpp

#ifndef POWERUP2_H
#define POWERUP2_H

#include "Obstacle.hpp"

class PowerUp2 : public Obstacle {
public:
    // Constructor for PowerUp2, taking a renderer, and initial x and y coordinates
    PowerUp2(SDL_Renderer* renderer, int x, int y);

    // Function to update the PowerUp2's state
    void update();

    // Function to reset the PowerUp2's position
    void reset(int x, int y);

    // Getter function for the x coordinate
    int getXPosition();

    // Getter function for the y coordinate
    int getYPosition();

    // Function to check if the PowerUp2 is active
    bool isActive() const;

    // Function to deactivate the PowerUp2
    void destroypowerup();

private:
    bool active; // Member variable to track the PowerUp2's activity status
};

#endif // POWERUP2_H
