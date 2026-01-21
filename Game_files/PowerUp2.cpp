// PowerUp2.cpp

#include "Powerup2.hpp"

// PowerUp2 constructor, calling the base class constructor with the provided renderer, x, and y coordinates
PowerUp2::PowerUp2(SDL_Renderer* renderer, int x, int y)
    : Obstacle(renderer, "powerup2.png", x, y) {
    // The constructor of the base class (Obstacle) is called with the specified image path and coordinates
}

const int SCREEN_HEIGHT = 800;

// Function to update the PowerUp2's state
void PowerUp2::update() {
    // Move the power-up downward
    yPosition += 4; // Adjust the speed as needed

    // If the power-up reaches the bottom, reset its position to the top with a new x coordinate
    if (yPosition >= SCREEN_HEIGHT) {
        yPosition = 0;
        xPosition = rand() % 600; // Set a new random x coordinate
    }
}

// Function to reset the PowerUp2's position
void PowerUp2::reset(int x, int y) {
    active = true;
    xPosition = x;
    yPosition = y;
    // Additional reset logic if needed
}

// Getter function for the x coordinate
int PowerUp2::getXPosition() {
    return xPosition;
}

// Getter function for the y coordinate
int PowerUp2::getYPosition() {
    return yPosition;
}

// Function to check if the PowerUp2 is active
bool PowerUp2::isActive() const {
    return active;
}

// Function to deactivate the PowerUp2
void PowerUp2::destroypowerup() {
    active = false;
}
