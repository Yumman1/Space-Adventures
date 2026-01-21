// ScoreTracker.cpp

#include "scoretracker.hpp"
#include <iostream>

// Constructor for ScoreTracker, taking a renderer and an initial score
ScoreTracker::ScoreTracker(SDL_Renderer* renderer, int initialScore)
    : score(initialScore), font(nullptr), texture(nullptr), textColor({255, 255, 0}) {
    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        // Handle TTF initialization error
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
    } else {
        // Load the TTF font
        font = TTF_OpenFont("font1.ttf", 30); // Replace "your_font_file.ttf" with the path to your TTF font file
        if (font == nullptr) {
            // Handle font loading error
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        }
    }
}

// Destructor for ScoreTracker
ScoreTracker::~ScoreTracker() {
    // Close the TTF font and quit SDL_ttf
    TTF_CloseFont(font);
    TTF_Quit();
    // Destroy the texture
    SDL_DestroyTexture(texture);
}

// Function to update the score by a given value
void ScoreTracker::updateScore(int value) {
    // Increment the score
    *this += value; 
}

// Function to render the score on the screen
void ScoreTracker::render(SDL_Renderer* renderer) {
    // Convert the score integer to a string
    std::string scoreText = "(score: " + std::to_string(score) + ")";
    // Render the score text
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
    if (textSurface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);

        if (texture != nullptr) {
            // Get the width and height of the rendered text
            int textWidth, textHeight;
            SDL_QueryTexture(texture, nullptr, nullptr, &textWidth, &textHeight);

            // Set the position to render the text
            SDL_Rect textRect = {10, 750, textWidth, textHeight};

            // Render the text
            SDL_RenderCopy(renderer, texture, nullptr, &textRect);
        }
    }
}

// Function to reset the score to zero
void ScoreTracker::reset() {
    score = 0;
}

// Function to get the current score
int ScoreTracker::getScore() const {
    return score;
}
