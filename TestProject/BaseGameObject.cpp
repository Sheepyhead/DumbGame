//
// Created by sheepy on 4/26/18.
//

#include "BaseGameObject.h"
#include "Game.h"
#include "CImg.h"

void BaseGameObject::update() {

}

void BaseGameObject::draw(long frameRatio) {
    sheepy::engine::mainCanvas.display(*sprite);
}

BaseGameObject::BaseGameObject(std::string spritePath, sheepy::engine::Transform transform) : transform(transform) {
    sprite = new cimg_library::CImg<float>(spritePath.c_str());
}

BaseGameObject::~BaseGameObject() {
    delete sprite;
}
