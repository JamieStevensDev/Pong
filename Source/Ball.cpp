//
// Created by j36-stevens on 04/12/2018.
//

#include "Ball.h"
#include <math.h>

Ball::Ball() = default;

Ball::~Ball() = default;

Ball::Ball(float x, float y)
{
    x_pos = x;
    y_pos = y;
}

void Ball::normalise()
{
    x_pos = x_pos /sqrt((x_pos*x_pos)+(y_pos*y_pos));
    y_pos = y_pos /sqrt((x_pos*x_pos)+(y_pos*y_pos));
}

Ball Ball::operator*(float scalar)
{
    return Ball(x_pos * scalar, y_pos * scalar);
}
