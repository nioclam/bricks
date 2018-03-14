/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_PHILOSOPHER_PHILOSOPHER_H__
#define __BRICKS_PHILOSOPHER_PHILOSOPHER_H__ 1

#include <bricks/chaos/chaos.h>

namespace bricks
{

/**
 * 哲学家
 * 哲学家的终极问题：我是谁？
 */
class Philosopher
{
    /**
     * Philosopher is who know 'who am I?'.
     */
    virtual char *whoami(Chaos *chaos = this_player->stringPool) = 0;
};

}

#include "named.h"
#include "whoami.h"
#include "whereami.h"

#endif /* #ifndef __BRICKS_PHILOSOPHER_PHILOSOPHER_H__ */
