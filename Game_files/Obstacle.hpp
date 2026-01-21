// Obstacle.hpp


// Include guard to prevent multiple inclusions of the header
#ifndef OBSTACLE_H
#define OBSTACLE_H
// Include necessary headers
#include <SDL.h>
#include <string>

// Class declaration for Obstacle
class Obstacle {
public:

    // Constructor taking renderer, image path, and initial coordinates
    Obstacle(SDL_Renderer* renderer, const std::string& imagePath, int x, int y);
    // Virtual destructor for proper cleanup in derived classes
    virtual ~Obstacle(); 
    void render(SDL_Renderer* renderer);// Function to render the obstacle on the screen
    void render1(SDL_Renderer* renderer, int a, int b); // Function to render the obstacle with additional parameters
    void update(); // Function to update the obstacle's state
    void destroy(); // Function to destroy the rendered image
    virtual void reset(int x, int y) = 0; // Pure virtual function for resetting position

protected:
    SDL_Texture* texture; // Texture for the obstacle's image
    int xPosition; // X-coordinate of the obstacle
    int yPosition; // Y-coordinate of the obstacle
    
};
// End of include guard
#endif // OBSTACLE_H
