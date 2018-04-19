/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_SPIRIT_H__
#define __BRICKS_AZRAEL_SPIRIT_H__ 1

#include "spiritfreer.h"

namespace bricks
{

/**
 * 接口：能够自我解脱的灵魂
 */
class Spirit
{
protected:
    /**
     * 自我解脱
     * @return NULL 总是返回NULL
     */
    virtual void *destroy() = 0;

protected:
    friend class SpiritFreer;
};

}

#endif /* #ifndef __BRICKS_AZRAEL_SPIRIT_H__ */
