/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_PHILOSOPHER_PHILOSOPHER_H__
#define __BRICKS_PHILOSOPHER_PHILOSOPHER_H__ 1

#include "../chaos.h"

namespace bricks
{

/**
 * 哲学家
 * 哲学家的终极问题：我是谁？
 */
class Philosopher
{
public:
    /**
     * Philosopher is who know 'who am I?'.
     */
    virtual const char *whoami(Chaos *chaos) = 0;
};

}

#endif /* #ifndef __BRICKS_PHILOSOPHER_PHILOSOPHER_H__ */
