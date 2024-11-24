#ifndef TEXT_H
#define TEXT_H

#include "main.h"

class Message {
    public:
        Message(std::shared_ptr<SDL_Renderer> renderer);

        void init(bool paused, double delay);
        void update(bool paused, double delay);
        void draw();

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
        SDL_Rect rect;
        SDL_Color color;
        unsigned int score;
};

#endif
