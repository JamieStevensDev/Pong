//
// Created by Huxy on 03/10/2018.
//

#include <Engine/DebugPrinter.h>
#include <Engine/Input.h>
#include <Engine/InputEvents.h>
#include <Engine/Keys.h>
#include <Engine/Platform.h>
#include <Engine/Sprite.h>
#include <iostream>
#include "MyGame.h"
#include "Ball.h"

MyGame::MyGame()
{
    game_width = 1024;
    game_height = 768;
    std::srand(time(NULL));
}
MyGame::~MyGame()
{
    this->inputs->unregisterCallback(key_callback_id);

    if (background)
    {
        delete background;
        background = nullptr;
    }

    if (ball)
    {
        delete ball;
        ball = nullptr;
    }

    if(paddle_left)
    {
        delete paddle_left;
        paddle_left = nullptr;
    }

    if(paddle_right)
    {
        delete paddle_right;
        paddle_right = nullptr;
    }
}

bool MyGame::init()
{
    game_name = "Pong";

    if (!initAPI())
    {
        return false;
    }
    // enable noob mode
    inputs->use_threads = false;    

    renderer->setSpriteMode(ASGE::SpriteSortMode::IMMEDIATE);
    renderer->setWindowTitle("Pong");

    toggleFPS();

    renderer->setClearColour(ASGE::COLOURS::BLACK);

    ball = renderer->createRawSprite();
    ball->loadTexture("/data/Kenney/png/ballGrey.png");
    ball->width(15);
    ball->height(15);
    ball->yPos(game_height/2);
    ball->xPos(game_width/2);

    paddle_left = renderer->createRawSprite();
    paddle_left->loadTexture("/data/Kenney/png/paddleBlu.png");
    paddle_left->width(20);
    paddle_left->height(120);
    paddle_left->yPos(game_height/2);
    paddle_left->xPos(50);

    paddle_right = renderer->createRawSprite();
    paddle_right->loadTexture("/data/Kenney/png/paddleRed.png");
    paddle_right->width(20);
    paddle_right->height(120);
    paddle_right->yPos(game_height/2);
    paddle_right->xPos(954);

    key_callback_id = inputs->addCallbackFnc(
            ASGE::E_KEY, &MyGame::keyHandler, this);

    return true;
}

void MyGame::update(const ASGE::GameTime &us)
{
    if (!in_menu)
    {
        // grab the current position
        float y_pos = ball->yPos();
        float x_pos = ball->xPos();
        float vect_y = 4;
        float vect_x = 3;

        if (ball->yPos() <= 0)
        {
            going_up = false;
        }

        if (ball->yPos() >= game_height)
        {
            going_up = true;
        }

        if (ball->xPos() <= 0)
        {
            p2_score++;
            spawn();

            x_pos = ball->xPos();
            ball->xPos(x_pos);
            y_pos = ball->yPos();
            ball->yPos(y_pos);

        }

        if (ball->xPos() >= game_width)
        {
            p1_score++;
            spawn();

            x_pos = ball->xPos();
            ball->xPos(x_pos);
            y_pos = ball->yPos();
            ball->yPos(y_pos);
        }

        if (going_up)
        {
            Ball *ball_velocity = new Ball(vect_x, vect_y);
            ball_velocity->normalise();
            ball_velocity->operator*(0.5);
            y_pos -= 400 * (us.delta_time.count() / 1000.f);
            ball->yPos(y_pos);
        }

        if (!going_up)
        {
            Ball *ball_velocity = new Ball(vect_x, vect_y);
            ball_velocity->normalise();
            ball_velocity->operator*(0.5);
            y_pos += 400 * (us.delta_time.count() / 1000.f);
            ball->yPos(y_pos);
        }

        if (going_left)
        {
            Ball *ball_velocity = new Ball(vect_x, vect_y);
            ball_velocity->normalise();
            ball_velocity->operator*(0.5);
            x_pos -= 400 * (us.delta_time.count() / 1000.f);
            ball->xPos(x_pos);
        }

        if (!going_left)
        {
            Ball *ball_velocity = new Ball(vect_x, vect_y);
            ball_velocity->normalise();
            ball_velocity->operator*(0.5);
            x_pos += 400 * (us.delta_time.count() / 1000.f);
            ball->xPos(x_pos);
        }

        paddle_collision();

        if (p2_score > p1_score + 3 && !going_left)
        {
            Ball *ball_velocity = new Ball(vect_x, vect_y);
            ball_velocity->normalise();
            ball_velocity->operator*(0.5);
            x_pos += 300 * (us.delta_time.count() / 1000.f);
            ball->xPos(x_pos);
        }
        if (p1_score > p2_score + 3 && !going_left)
        {
            Ball *ball_velocity = new Ball(vect_x, vect_y);
            ball_velocity->normalise();
            ball_velocity->operator*(0.5);
            x_pos += 300 * (us.delta_time.count() / 1000.f);
            ball->xPos(x_pos);
        }
    }
}

void MyGame::paddle_collision()
        {
            if (ball->xPos() >= (paddle_left->xPos() - (paddle_left->width() / 2)) &&
                ball->xPos() <= (paddle_left->xPos() + (paddle_left->width() / 2)) &&
                ball->yPos() >= (paddle_left->yPos() - (paddle_left->height() / 2)) &&
                ball->yPos() <= (paddle_left->yPos() + (paddle_left->height() / 2)))
            {
                going_left = false;

                if (paddle_left->height() > 60)
                {
                    paddle_left->height(paddle_left->height() - 10);
                }
            }

            if (ball->xPos() >= (paddle_right->xPos() - (paddle_right->width() / 2)) &&
                ball->xPos() <= (paddle_right->xPos() + (paddle_right->width() / 2)) &&
                ball->yPos() >= (paddle_right->yPos() - (paddle_right->height() / 2)) &&
                ball->yPos() <= (paddle_right->yPos() + (paddle_right->height() / 2)))
            {
                going_left = true;

                if (paddle_right->height() > 60)
                {
                    paddle_right->height(paddle_right->height() - 10);
                }
            }
        }

void MyGame::spawn()
{
    float start_x = 1028  / 2;
    float start_y = 768 / 2;

    ball->xPos(start_x);
    ball->yPos(start_y);
}

void MyGame::render(const ASGE::GameTime &us)
{
    renderer->setFont(0);

    if (in_menu)
    {
        //render text to introduce the game
        std::string welcome = "Welcome to Pong!";
        renderer->renderText(welcome, 350, 200,1.0, ASGE::COLOURS::DARKORANGE);
        //ask user to press enter to start the game
        std::string start = "Please press enter to start the game.";
        renderer->renderText(start, 300, 320, 1.0, ASGE::COLOURS::DARKORANGE);
    }
    else
    {

        std::string p1score_str = "SCORE: " + std::to_string(p1_score);
        renderer->renderText(p1score_str.c_str(), 100, 25, 1.0, ASGE::COLOURS::DARKORANGE);

        std::string p2score_str = "SCORE: " + std::to_string(p2_score);
        renderer->renderText(p2score_str.c_str(), 850, 25, 1.0, ASGE::COLOURS::DARKORANGE);

        renderer->renderSprite(*ball);
        renderer->renderSprite(*paddle_left);
        renderer->renderSprite(*paddle_right);
    }
}

void MyGame::keyHandler(const ASGE::SharedEventData data)
{
    auto key = static_cast<const ASGE::KeyEvent*>(data.get());

    if (key->key == ASGE::KEYS::KEY_ENTER &&
        key->action == ASGE::KEYS::KEY_RELEASED)
    {
        // set the in menu boolean to false //
        in_menu = false;
    }
    if (key->key == ASGE::KEYS::KEY_W)
    {
        float left_y = 0;
        if (paddle_left->yPos() <= 10)
        {

        }
        else
            {
            left_y = paddle_left->yPos();
            left_y = left_y - 25;
            paddle_left->yPos(left_y);
            }
    }
    if (key->key == ASGE::KEYS::KEY_S)
    {
        float left_y = 0;
        if (paddle_left->yPos() >= game_height - paddle_left->height())
        {

        }
        else
            {
            left_y = paddle_left->yPos();
            left_y = left_y + 25;
            paddle_left->yPos(left_y);
            }
    }
    if (key->key == ASGE::KEYS::KEY_UP)
    {
        float right_y = 0;
        if (paddle_right->yPos() <= 10)
        {

        }
        else
        {
            right_y = paddle_right->yPos();
            right_y = right_y - 25;
            paddle_right->yPos(right_y);
        }
    }
    if (key->key == ASGE::KEYS::KEY_DOWN)
    {
        float right_y = 0;
        if (paddle_right->yPos() >= game_height - paddle_right->height())
        {

        }
        else
        {
            right_y = paddle_right->yPos();
            right_y = right_y + 25;
            paddle_right->yPos(right_y);
        }
    }
    if (key->key == ASGE::KEYS::KEY_ESCAPE)
    {
        signalExit();
    }
}


