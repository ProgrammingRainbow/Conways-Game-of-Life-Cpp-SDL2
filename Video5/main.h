#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <format>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

constexpr int SDL_FLAGS = (SDL_INIT_VIDEO | SDL_INIT_AUDIO);
constexpr int IMG_FLAGS = IMG_INIT_PNG;

constexpr const char *WINDOW_TITLE = "Conway's Game of Life";
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

constexpr int SIZE = 10;
#define RENDERER_COLOR 0, 0, 0, 255
#define CELL_COLOR 128, 128, 128, 255

constexpr int TARGET_DELAY = 128;

#endif
