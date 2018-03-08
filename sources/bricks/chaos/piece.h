/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_PIECE_H__
#define __BRICKS_CHAOS_PIECE_H__ 1

#include "byte.h"

namespace bricks
{

class Chaos;

/**
 * 连续
 */
class Piece
{
public:
    virtual size_t lowerPosition() = 0;
    virtual size_t upperPosition() = 0;
    virtual size_t length();
    virtual byte_t *data() = 0;
    virtual Chaos *chaos() = 0;
    virtual void moveNext() = 0;
    virtual void movePrev() = 0;
};

}

#endif /* #ifndef __BRICKS_CHAOS_PIECE_H__ */
