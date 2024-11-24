#ifndef BOARD_H
#define BOARD_H

#include "main.h"

class Board {
    public:
        Board(std::shared_ptr<SDL_Renderer> renderer);

        void init();
        void reset();
        void clear();
        void edit(int x, int y);
        void update();
        void draw();

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        const int rows;
        const int columns;
        std::vector<std::vector<int>> board;
        std::vector<std::vector<int>> next_board;
        SDL_Rect rect;
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<int> rand_cell;
};

#endif
