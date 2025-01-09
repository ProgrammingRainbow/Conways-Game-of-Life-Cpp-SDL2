#include "message.h"

void Message::init(bool paused, double delay) {
    this->font.reset(TTF_OpenFont("fonts/freesansbold.ttf", FONT_SIZE));
    if (!this->font) {
        auto error = std::format("Error creating font: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    this->update(paused, delay);
}

void Message::update(bool paused, double delay) {
    std::string text;

    if (paused) {
        text = "Paused";
    } else {
        text = "Speed: " + std::to_string(128.0 / delay);
    }

    text.erase(text.find_last_not_of('0') + 1, std::string::npos);
    text.erase(text.find_last_not_of('.') + 1, std::string::npos);

    this->surface.reset(
        TTF_RenderText_Blended(this->font.get(), text.c_str(), this->color));
    if (!this->surface) {
        auto error =
            std::format("Error creating a surface: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    this->image.reset(
        SDL_CreateTextureFromSurface(this->renderer.get(), surface.get()));
    if (!this->image) {
        auto error =
            std::format("Error creating a texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w,
                         &this->rect.h)) {
        auto error =
            std::format("Error while querying texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

void Message::draw() const {
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr,
                   &this->rect);
}
