// ScoreTracker.hpp
#ifndef SCORETRACKER_H
#define SCORETRACKER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class ScoreTracker {
public:
    // Constructor taking a renderer and an optional initial score
    ScoreTracker(SDL_Renderer* renderer, int initialScore = 0);

    // Destructor
    ~ScoreTracker();

    // Function to update the score by a given value
    void updateScore(int value);

    // Function to render the score on the screen
    void render(SDL_Renderer* renderer);

    // Function to reset the score to zero
    void reset();

    // Function to get the current score
    int getScore() const;

    // Overloaded += operator to increment the score
    ScoreTracker& operator+=(int value) {
        score += value;
        return *this;
    }

private:
    int score;
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Color textColor;
};

#endif // SCORETRACKER_H
