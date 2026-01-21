// PowerUp.hpp

#ifndef POWERUP_H
#define POWERUP_H

#include "Obstacle.hpp"

// PowerUp class declaration, inheriting from the Obstacle base class
class PowerUp : public Obstacle {
public:
    // Constructor for PowerUp, taking a renderer, and initial x and y coordinates
    PowerUp(SDL_Renderer* renderer, int x, int y);
    
    // Function to update the PowerUp's state
    void update();
    
    // Function to reset the PowerUp's position
    void reset(int x, int y);
    
    // Getter function for the x coordinate
    int getXPosition();
    
    // Getter function for the y coordinate
    int getYPosition();
    
    // Function to check if the PowerUp is active
    bool isActive() const;
    
    // Function to deactivate the PowerUp
    void destroypowerup();

private:
    bool active; // Member variable to track the PowerUp's activity status
};

#endif // POWERUP_H
