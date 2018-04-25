//
// Created by sheepy on 4/25/18.
//

#include "Game.h"
#include <chrono>

using namespace sheepy::engine;

Game::Game() {

    long previous = getCurrentTime();
    double lag = 0.0;
    while (true) {
        long current = getCurrentTime();
        long deltaTime = current - previous;
        previous = current; {
            std::cout << "There is lag: " << lag << std::endl;
            update();
            lag += deltaTime;

            while (lag >= MS_PER_UPDATE)
            lag -= MS_PER_UPDATE;
        }

        draw();
    }
}

Game::~Game() {

}

long Game::getCurrentTime() {
    return std::chrono::system_clock::now().time_since_epoch().count();
}

void Game::update() {
}

void Game::draw() {
    std::cout << "Draw called" << std::endl;
}

