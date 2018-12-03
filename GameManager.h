//
// Created by leon on 11/20/18.
//

#pragma once

#include <SDL.h>

#include "Utils/Logging.h"

namespace Starless {
    const int WIDTH = 1080;
    const int HEIGHT = 800;

    enum GameView {
        MAIN_MENU
    };

    class GameManager {
    public:
        static void init(Logger* logger);
        static void close();
        static bool running();
        static void update();
    private:
        static SDL_Event event;
        static SDL_Window* window;

        static bool isRunning;

        static Logger* log;
        static GameView currentView;
        static void SDLInit();
        static void eventManager();
        static void SDLFinish();
    };
}