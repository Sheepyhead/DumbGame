//
// Created by sheepy on 4/25/18.
//

#include "Game.h"
#include <chrono>

using namespace sheepy::engine;

Game::Game() {
    initialize();

    auto previous = getCurrentTime();
    auto lag = 0.0;
    while (true) {
        auto current = getCurrentTime();
        auto sinceLast = current - previous;
        auto deltaTime = (std::chrono::duration_cast<std::chrono::nanoseconds>(sinceLast)) / 1000.0;

        previous = current;
        lag += deltaTime.count();

        while (lag >= MS_PER_UPDATE)
        {
            update();

            // Clamp lag to be min 0
            lag -= MS_PER_UPDATE == 0 ? 0 : lag;
        }

        draw(static_cast<const long>(lag / MS_PER_UPDATE));
    }
}

Game::~Game() {
}

std::chrono::high_resolution_clock::time_point Game::getCurrentTime() {
    return std::chrono::high_resolution_clock::now();
}

void Game::update() {
    for (auto &object : objects) {
        object.update();
    }
}

void Game::draw(long frameRatio) {
    for (auto &object : objects) {
        object.draw(frameRatio);
    }
}

void Game::initialize() {

}

void Game::addGameObject(GameObject&& object) {
    objects.push_back(object);
}

int main() {
    sheepy::engine::Game game {};
    return 0;
}

namespace sheepy {
namespace engine {
cimg_library::CImgDisplay mainCanvas{};
}
}