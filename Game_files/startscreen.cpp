#include "gamesettings.hpp"
#include "startscreen.hpp"


StartScreen::StartScreen(SDL_Renderer* renderer) : renderer(renderer) {
    startScreenTexture = loadTexture("gamebackground.png");
    
    buttons[0].texture = loadTexture("EASY.png");
    buttons[1].texture = loadTexture("Medium.png");
    buttons[2].texture = loadTexture("hard.png");

    // if (startScreenTexture == nullptr || startButtonTexture == nullptr) {
    //     std::cerr << "Failed to load start screen or start button image." << std::endl;
       
    // }
    buttons[0].x = 220;
    buttons[0].y = 400;
    buttons[0].width = 150;
    buttons[0].height = 50;

    buttons[1].x = 200;
    buttons[1].y = 550;
    buttons[1].width = 200;
    buttons[1].height = 50;

    buttons[2].x = 220;
    buttons[2].y = 700;
    buttons[2].width = 150;
    buttons[2].height = 50;
}

StartScreen::~StartScreen() {
    SDL_DestroyTexture(startScreenTexture);
    SDL_DestroyTexture(startButtonTexture);
}

bool StartScreen::show(SDL_Event& event) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, startScreenTexture, nullptr, nullptr);

    // Render "Start" button
    for (int i = 0; i < 3; ++i) {
        SDL_Rect buttonRect = { buttons[i].x, buttons[i].y, buttons[i].width, buttons[i].height };
        SDL_RenderCopy(renderer, buttons[i].texture, nullptr, &buttonRect);
    }

    SDL_RenderPresent(renderer);

    // Handle events
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            return false;  
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_RETURN) {
                return false;  
            }
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= buttons[0].x && mouseX <= buttons[0].x + buttons[0].width &&
                mouseY >= buttons[0].y && mouseY <= buttons[0].y + buttons[0].height) {
                    GameSettings::asteroidSpeed1 = 5;
                    GameSettings::asteroidSpeed2 = 7;
                    GameSettings::asteroidSpeed3 = 9;
                    GameSettings::level = 1;
                return false; // Exit start screen and start Level 1
            }
            else if (mouseX >= buttons[1].x && mouseX <= buttons[1].x + buttons[1].width &&
                mouseY >= buttons[1].y && mouseY <= buttons[1].y + buttons[1].height) {
                    GameSettings::asteroidSpeed1 = 10;
                    GameSettings::asteroidSpeed2 = 12;
                    GameSettings::asteroidSpeed3 = 14;
                    GameSettings::level = 2;

                return false; // Exit start screen and start Level 2
            }
            else if (mouseX >= buttons[2].x && mouseX <= buttons[2].x + buttons[2].width &&
                mouseY >= buttons[2].y && mouseY <= buttons[2].y + buttons[2].height) {
                    GameSettings::asteroidSpeed1 = 12;
                    GameSettings::asteroidSpeed2 = 15;
                    GameSettings::asteroidSpeed3 = 16;
                    GameSettings::level = 3; 
                return false; // Exit start screen for Level 3
            }
        }
    }

    SDL_Delay(30);  

    return true;  
}

SDL_Texture* StartScreen::loadTexture(const std::string& path) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
    }
    return texture;
}
