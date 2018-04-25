//
// Created by sheepy on 4/25/18.
//

#ifndef TESTPROJECT_GAME_H
#define TESTPROJECT_GAME_H

#include <iostream>
#include <cstdio>
#include <CImg.h>

namespace sheepy {
namespace engine {
class Game {
public:
    Game();
    ~Game();

    // Pure virtual methods
    void update();
    void draw();

private:
    //Internal methods
    long getCurrentTime();
    const int fps = 60;
    const double MS_PER_UPDATE = 100.0/fps;
};
}
}

int main() {
    sheepy::engine::Game game {};
    return 0;
}


#endif //TESTPROJECT_GAME_H
