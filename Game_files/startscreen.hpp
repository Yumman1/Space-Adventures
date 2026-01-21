// StartScreen.hpp
#ifndef STARTSCREEN_HPP
#define STARTSCREEN_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class StartScreen {
public:
    StartScreen(SDL_Renderer* renderer);
    ~StartScreen();

    // Function to display the start screen and handle events
    bool show(SDL_Event& event);

private:
    // Pointer to the SDL renderer
    SDL_Renderer* renderer;

    // Textures for the start screen and start button
    SDL_Texture* startScreenTexture;
    SDL_Texture* startButtonTexture;

    // Coordinates and dimensions of the start button
    int startButtonX;
    int startButtonY;
    int startButtonWidth;
    int startButtonHeight;

    // Structure representing a button with its texture and position
    struct Button {
        SDL_Texture* texture;
        int x;
        int y;
        int width;
        int height;
    };

    // Array of buttons
    Button buttons[3];

    // Function to load a texture from a file path
    SDL_Texture* loadTexture(const std::string& path);
};

#endif // STARTSCREEN_HPP
