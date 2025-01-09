#include "board.h"

void Board::init() { reset(); }

void Board::reset() {
    for (std::size_t row = 0; row < this->rows; ++row) {
        for (std::size_t column = 0; column < this->columns; ++column) {
            this->board[row][column] = rand_cell(this->gen);
        }
    }
}

void Board::clear() {
    for (std::size_t row = 0; row < this->rows; ++row) {
        for (std::size_t column = 0; column < this->columns; ++column) {
            this->board[row][column] = 0;
        }
    }
}

void Board::draw() {
    SDL_SetRenderDrawColor(this->renderer.get(), CELL_COLOR);
    for (std::size_t row = 0; row < rows; ++row) {
        this->rect.y = static_cast<int>(row) * SIZE;
        for (std::size_t column = 0; column < columns; ++column) {
            this->rect.x = static_cast<int>(column) * SIZE;
            if (board[row][column] == 1) {
                SDL_RenderFillRect(this->renderer.get(), &this->rect);
            }
        }
    }
}
