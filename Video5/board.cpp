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

void Board::edit(int x, int y) {
    int column = x / SIZE;
    int row = y / SIZE;
    if (row < rows && column < this->columns) {
        this->board[row][column] = 1 - this->board[row][column];
    }
}

void Board::update() {
    for (int row = 0; row < this->rows; ++row) {
        for (int column = 0; column < this->columns; ++column) {
            int count = 0;
            for (int y = row - 1; y <= row + 1; ++y) {
                for (int x = column - 1; x <= column + 1; ++x) {
                    if (y == row && x == column)
                        continue;
                    int wrapped_row = (y + this->rows) % this->rows;
                    int wrapped_column = (x + this->columns) % this->columns;
                    count += this->board[wrapped_row][wrapped_column];
                }
            }
            if (this->board[row][column] == 1 && (count > 1 && count < 4)) {
                this->next_board[row][column] = 1;
            } else if (this->board[row][column] == 0 && count == 3) {
                this->next_board[row][column] = 1;
            } else {
                this->next_board[row][column] = 0;
            }
        }
    }
    this->board.swap(this->next_board);
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
