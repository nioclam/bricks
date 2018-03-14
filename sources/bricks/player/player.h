/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_PLAYER_PLAYER_H__
#define __BRICKS_PLAYER_PLAYER_H__ 1

#include <thread>
#include <functional>
#include <bricks/chaos/chaos.h>

namespace bricks
{

class Player : std::thread
{
public:
    Player();
    Player(std::function<void()> game);

protected:
    void play(std::function<void()> game);

public:
    Chaos      *m_stringPool;
    ObjectPool *m_objectPool;
};

extern thread_local Player *this_player;

}

#endif /* #ifndef __BRICKS_PLAYER_PLAYER_H__ */
