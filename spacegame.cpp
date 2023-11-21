#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Spaceship.hpp"
#include "Obstacle.hpp"
#include "Asteroid.hpp" // Include the new Asteroid class

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;
const int SCROLL_SPEED = 1; // Adjust this value to control the scrolling speed

SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& path) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
    }
    return texture;
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG)) {
        std::cerr << "SDL_image initialization failed: " << IMG_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SpaceExplorer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Texture* backgroundTexture = loadTexture(renderer, "Background 1.png");
    if (backgroundTexture == nullptr) {
        std::cerr << "Failed to load background image." << std::endl;
        return 1;
    }

    SDL_Texture* asteroidTexture = loadTexture(renderer, "asteroid.png");
    if (asteroidTexture == nullptr) {
        std::cerr << "Failed to load asteroid image." << std::endl;
        return 1;
    }


    int bgY = 0;

    bool quit = false;
    SDL_Event e;
    SDL_Texture* currentTexture = backgroundTexture;
    Spaceship spaceship(renderer, "ss.png", SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50);

    // Create an Asteroid object
    Asteroid asteroid(renderer, rand()%600, 0);

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        spaceship.moveLeft();
                        break;
                    case SDLK_RIGHT:
                        spaceship.moveRight();
                        break;
                    // Add more cases for other keys if needed
                }
            }
        }
        
        // Inside your main game loop:

        // Get the rectangles representing the spaceship, obstacle, and asteroid
        SDL_Rect spaceshipRect = spaceship.getCollider();
        SDL_Rect obstacleRect = obstacle.getCollider();
        SDL_Rect asteroidRect = asteroid.getCollider();

        // Check for collision between spaceship and obstacle
        if (checkCollision(spaceshipRect, obstacleRect)) {
            // Collision with obstacle detected! Handle it here.
            std::cout << "Collision with obstacle detected!" << std::endl;
            // Perform actions like reducing health, ending the game, etc.
            quit = true; // For example, you could end the game on collision
        }

        // Check for collision between spaceship and asteroid
        if (checkCollision(spaceshipRect, asteroidRect)) {
            // Collision with asteroid detected! Handle it here.
            std::cout << "Collision with asteroid detected!" << std::endl;
            // Perform actions like reducing health, ending the game, etc.
            quit = true; // For example, you could end the game on collision
        }






        spaceship.update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect dstRect1 = {0, bgY, SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_Rect dstRect2 = {0, bgY - SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_RenderCopy(renderer, currentTexture, nullptr, &dstRect1);
        SDL_RenderCopy(renderer, currentTexture, nullptr, &dstRect2);

        bgY += SCROLL_SPEED; // Adjust the scrolling speed here
        spaceship.render(renderer);

        // Render and update the asteroid
        asteroid.update();
        asteroid.render(renderer);

        if (bgY >= SCREEN_HEIGHT) {
            bgY = 0;
        }

        SDL_RenderPresent(renderer);

        // Introduce a delay to control the scrolling speed
        SDL_Delay(30); // Adjust the delay time (in milliseconds) to control the speed
    }

    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(asteroidTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
