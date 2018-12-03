//
// Created by leon on 11/20/18.
//

#include "GameManager.h"

bool Starless::GameManager::isRunning;
Logger* Starless::GameManager::log;
Starless::GameView Starless::GameManager::currentView;
SDL_Event Starless::GameManager::event;
SDL_Window* Starless::GameManager::window;

void Starless::GameManager::init(Logger* logger) {
    log = logger;
    isRunning = true;
    currentView = GameView::MAIN_MENU;

    SDLInit();
}

void Starless::GameManager::close() {
    SDLFinish();
}

bool Starless::GameManager::running() {
    return isRunning;
}

void Starless::GameManager::update() {
    eventManager();
}

void Starless::GameManager::eventManager() {
    while(SDL_PollEvent(&event) != 0) {
        if(event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Starless::GameManager::SDLInit() {
    window = nullptr;
    SDL_Surface* windowSurface = nullptr;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        log->error("SDL could not initialize! SDL Error: " + std::string(SDL_GetError()));
    }

    // NOLINTNEXTLINE
    window = SDL_CreateWindow("Starless", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        log->error("SDL could create window! SDL Error: " + std::string(SDL_GetError()));
    }
    log->info("Created window [" + std::to_string(WIDTH) + "x" + std::to_string(HEIGHT) + "]");

    windowSurface = SDL_GetWindowSurface(window);

    SDL_FillRect(windowSurface, nullptr, SDL_MapRGB(windowSurface->format, 255, 255, 255));
    SDL_UpdateWindowSurface(window);
}

void Starless::GameManager::SDLFinish() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
