/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include <stdexecpt>
#include "player.h"

using namespace bricks;
thread_local Player *bricks::this_player = nullptr;

Player::Player()
    : std::thread()
{
    bricks::this_player = this;
}

Player::Player(std::function<void()> game)
    : std::thread(&Player::play, this, game)
{
}

void Player::play(std::function<void()> game)
{
    bricks::this_player = this;
    game();
}
