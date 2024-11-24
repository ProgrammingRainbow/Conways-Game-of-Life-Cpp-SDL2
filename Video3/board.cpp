#include "board.h"

Board::Board(std::shared_ptr<SDL_Renderer> renderer)
    : renderer{renderer},
      rows{WINDOW_HEIGHT / SIZE},
      columns{WINDOW_WIDTH / SIZE},
      board{(unsigned)rows, std::vector<int>((unsigned)columns, 0)},
      next_board{(unsigned)rows, std::vector<int>((unsigned)columns, 0)},
      rect{0, 0, SIZE - 1, SIZE - 1},
      rd{},
      gen{rd()},
      rand_cell{0, 1} {}

void Board::init() { reset(); }

void Board::reset() {
    for (int row = 0; row < this->rows; ++row) {
        for (int column = 0; column < this->columns; ++column) {
            this->board[row][column] = rand_cell(this->gen);
        }
    }
}

void Board::clear() {
    for (int row = 0; row < this->rows; ++row) {
        for (int column = 0; column < this->columns; ++column) {
            this->board[row][column] = 0;
        }
    }
}

void Board::draw() {
    SDL_SetRenderDrawColor(this->renderer.get(), CELL_COLOR);
    for (int row = 0; row < rows; ++row) {
        this->rect.y = row * SIZE;
        for (int column = 0; column < columns; ++column) {
            this->rect.x = column * SIZE;
            if (board[row][column] == 1) {
                SDL_RenderFillRect(this->renderer.get(), &this->rect);
            }
        }
    }
}
