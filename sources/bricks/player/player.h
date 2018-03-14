/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_PLAYER_PLAYER_H__
#define __BRICKS_PLAYER_PLAYER_H__ 1

#include <thread>
#include <functional>
#include <bricks/chaos/chaos.h>

// object依赖player，为了避免循环引用，仅仅引入ObjectPool接口
#include "../object/objectpool.h"

namespace bricks
{

class Player : std::thread
{
public:
    Player();
    Player(Player *that);
    Player(Chaos *stringPool, ObjectPool *objectPool);
    Player(std::function<void()> game);

protected:
    void play(std::function<void()> game);

public:
    Chaos      *stringPool;
    ObjectPool *objectPool;
};

extern thread_local Player *this_player;

}

#endif /* #ifndef __BRICKS_PLAYER_PLAYER_H__ */
