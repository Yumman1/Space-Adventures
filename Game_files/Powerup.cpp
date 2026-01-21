// PowerUp.cpp

// Include the header file for PowerUp
#include "Powerup.hpp"

// Constructor for PowerUp, calling the base class constructor with image path and coordinates
PowerUp::PowerUp(SDL_Renderer* renderer, int x, int y)
    : Obstacle(renderer, "powerup.png", x, y) {
    // The constructor of the base class (Obstacle) is called with the specified image path and coordinates
}

// Constant representing the screen height
const int SCREEN_HEIGHT = 800;

// Function to update the PowerUp's state
void PowerUp::update() {
    // Move the power-up downward
    yPosition += 4; // Adjust the speed as needed

    // If the power-up reaches the bottom, reset its position to the top with a new x coordinate
    if (yPosition >= SCREEN_HEIGHT) {
        yPosition = 0;
        xPosition = rand() % 600; // Set a new random x coordinate
    }
}

// Function to reset the PowerUp's position
void PowerUp::reset(int x, int y) {
    active = true; // Reactivate the PowerUp
    xPosition = x; // Set new x coordinate
    yPosition = y; // Set new y coordinate
    // Additional reset logic can be added here if needed
}

// Getter function for the x coordinate
int PowerUp::getXPosition() {
    return xPosition;
}

// Getter function for the y coordinate
int PowerUp::getYPosition() {
    return yPosition;
}

// Function to check if the PowerUp is active
bool PowerUp::isActive() const {
    return active;
}

// Function to deactivate the PowerUp
void PowerUp::destroypowerup() {
    active = false;
}
