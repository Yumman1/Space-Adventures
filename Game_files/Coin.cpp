// Coin.cpp
#include "Coin.hpp"

Coin::Coin(SDL_Renderer* renderer, int x, int y)
    : Obstacle(renderer, "Coins.png", x, y), active(true) {
    // The constructor of the base class (Obstacle) is called with the specified image path and coordinates
}

void Coin::update() {
    if (active) {
        // Move the coin downward
        yPosition += 8; // Adjust the speed as needed

        // If the coin reaches the bottom, reset its position to the top with a new x coordinate
        if (yPosition >= 800) {
            yPosition = 0;
            xPosition = rand() % 600; // Set a new random x coordinate
        }
    }
}


// Check if the coin is active
bool Coin::isActive() const{
    return active;
}


// Deactivate the coin
void Coin::destroycoin() {
    active = false;
}


// Get the x-coordinate of the coin
int Coin::getXPosition()  {
    return xPosition; 
}

// Get the y-coordinate of the coin
int Coin::getYPosition() {
    return yPosition; 
}


// Reset the coin's position
void Coin::reset(int x, int y) {
    active = true;
    xPosition = x;
    yPosition = y;
}


// Bonus coin update implementation
void Coin::bonusupdate() {
    if (active) {
        // Move the coin downward
        yPosition += 8; // Adjust the speed as needed

        
        
    }
}