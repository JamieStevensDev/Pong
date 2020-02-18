//
// Created by j36-stevens on 04/12/2018.
//

#ifndef HELLOASGE_BALL_H
#define HELLOASGE_BALL_H

#include <string>
#include <Engine/OGLGame.h>

class Ball {
public:

    Ball();
    ~Ball();

    Ball(float x, float y);

    void normalise();
    Ball operator*(float scalar);

private:
    float x_pos = 0;
    float y_pos  = 0;

};


#endif //HELLOASGE_BALL_H
