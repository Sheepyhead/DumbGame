//
// Created by sheepy on 4/26/18.
//

#ifndef TESTPROJECT_BASEGAMEOBJECT_H
#define TESTPROJECT_BASEGAMEOBJECT_H


#include "GameObject.h"
#include "CImg.h"
#include <string>

class BaseGameObject : public sheepy::engine::GameObject {
public:
    BaseGameObject(std::string spritePath, sheepy::engine::Transform = {});
    ~BaseGameObject();

    void update() override;
    void draw(long frameRatio) override;

private:
    cimg_library::CImg<float> *sprite;
    sheepy::engine::Transform transform;
};


#endif //TESTPROJECT_BASEGAMEOBJECT_H
