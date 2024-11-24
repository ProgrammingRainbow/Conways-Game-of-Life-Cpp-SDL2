#ifndef FPS_H
#define FPS_H

#include "main.h"
#include <chrono>
#include <thread>

class Fps {
    public:
        Fps();

        void increaseSpeed();
        void decreaseSpeed();
        double getDelay();
        void update();
        void toggleFps();

        double dt;

    private:
        void show_fps();

        std::chrono::duration<double, std::milli> target_delay;
        const std::chrono::duration<double, std::milli> max_delay;
        std::chrono::time_point<std::chrono::steady_clock> last_time;
        std::chrono::time_point<std::chrono::steady_clock> current_time;
        std::chrono::duration<double, std::milli> carry_delay;
        std::chrono::duration<double, std::milli> first_elapsed;
        std::chrono::duration<double, std::milli> second_elapsed;
        std::chrono::time_point<std::chrono::steady_clock> last_fps;
        const std::chrono::steady_clock::duration fps_delay;
        unsigned int frames;
        bool enable_fps;
};

#endif
