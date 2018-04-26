//
// Created by sheepy on 4/25/18.
//

#ifndef TESTPROJECT_GAME_H
#define TESTPROJECT_GAME_H

#include <iostream>
#include <cstdio>
#include <CImg.h>
#include <chrono>

namespace sheepy {
namespace engine {
class Game {
public:
    Game();
    ~Game();

    // Game loop methods
    void update();
    void draw(const long frameRatio);

private:
    //Internal methods
    std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::duration<int64_t, std::ratio<1, 1000000000>>>
    getCurrentTime();


    const int fps = 60;
    const double MS_PER_UPDATE = 100.0/fps;
};
}
}


#endif //TESTPROJECT_GAME_H
