#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "fps.h"
#include "main.h"

class Game {
    public:
        Game();
        ~Game();

        void init_sdl();
        void init();
        void run();

    private:
        void togglePause();
        void increaseSpeed();
        void decreaseSpeed();
        void events();
        void update();
        void draw();

        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<Board> board;
        std::unique_ptr<Fps> fps;
        SDL_Event event;
        bool is_running;
        bool is_paused;
};

#endif
