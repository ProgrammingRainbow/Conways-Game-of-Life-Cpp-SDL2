#include "init_sdl.h"

void Game::init_sdl() {
    if (SDL_Init(SDL_FLAGS) != 0) {
        auto error = fmt::format("Error initializing SDL: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    int img_init = IMG_Init(IMG_FLAGS);
    if ((img_init & IMG_FLAGS) != IMG_FLAGS) {
        auto error =
            fmt::format("Error initializing SDL_image: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    this->window.reset(SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                                        WINDOW_HEIGHT, SDL_WINDOW_SHOWN),
                       SDL_DestroyWindow);
    if (!this->window) {
        auto error = fmt::format("Error creating window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->renderer.reset(
        SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer);
    if (!this->renderer) {
        auto error = fmt::format("Error creating renderer: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    SDL_Surface *icon_surf = IMG_Load("images/icon.png");
    if (icon_surf) {
        SDL_SetWindowIcon(this->window.get(), icon_surf);
        SDL_FreeSurface(icon_surf);
    } else {
        auto error =
            fmt::format("Error creating icon Surface: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}