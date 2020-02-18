//
// Created by Huxy on 03/10/2018.
//

#ifndef HELLOASGE_MYGAME_H
#define HELLOASGE_MYGAME_H

#include <Engine/OGLGame.h>
#include "Ball.h"

class MyGame : public ASGE::OGLGame
{
public:
    MyGame();
    ~MyGame();
    bool init() override;
    void update(const ASGE::GameTime& us) override;
    void render(const ASGE::GameTime& us) override;

private:
    void keyHandler(const ASGE::SharedEventData data);
    void spawn();
    void paddle_collision();

    int  key_callback_id = -1;
    ASGE::Sprite* background = nullptr;
    ASGE::Sprite* ball = nullptr;
    ASGE::Sprite* paddle_left = nullptr;
    ASGE::Sprite* paddle_right = nullptr;

    bool in_menu = true;
    int p1_score = 0;
    int p2_score = 0;

    bool going_up = true;
    bool going_left = true;

};




#endif //HELLOASGE_MYGAME_H
