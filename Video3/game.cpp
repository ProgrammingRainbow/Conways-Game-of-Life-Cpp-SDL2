#include "game.h"

Game::~Game() {
    this->board.reset();

    this->renderer.reset();
    this->window.reset();

    IMG_Quit();
    SDL_Quit();

    std::cout << "all clean!" << std::endl;
}

void Game::init() {
    this->init_sdl();

    this->board.reset(new Board(this->renderer));
    this->board->init();
}

void Game::events() {
    while (SDL_PollEvent(&this->event)) {
        switch (this->event.type) {
        case SDL_QUIT:
            this->is_running = false;
            return;
        case SDL_KEYDOWN:
            switch (this->event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                this->is_running = false;
                break;
            case SDL_SCANCODE_R:
                this->board->reset();
                break;
            case SDL_SCANCODE_C:
                this->board->clear();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Game::draw() {
    SDL_SetRenderDrawColor(this->renderer.get(), RENDERER_COLOR);
    SDL_RenderClear(this->renderer.get());

    this->board->draw();

    SDL_RenderPresent(this->renderer.get());
}

void Game::run() {
    while (this->is_running) {
        this->events();

        this->draw();

        SDL_Delay(16);
    }
}
