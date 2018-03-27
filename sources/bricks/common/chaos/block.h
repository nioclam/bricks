/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_BLOCK_H__
#define __BRICKS_CHAOS_BLOCK_H__ 1

#include "byte.h"

namespace bricks
{

/**
 * 一块内存
 */
class Block
{
public:
    Block()
        : data(nullptr)
        , length(0)
    {
    }
    
    Block(byte_t *d, size_t l)
        : data(d)
        , length(l)
    {
    }

public:
    byte_t *data;
    size_t  length;
};

}

#endif /* #ifndef __BRICKS_CHAOS_BLOCK_H__ */
