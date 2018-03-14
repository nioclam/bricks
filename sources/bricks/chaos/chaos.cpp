/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "chaos.h"

using namespace bricks;

Block Chaos::access(int position)
{
    Azrael<Piece> piece;

    if (-1 == piece.redeem(chaos.locate(position)))
    {
        return Block(nullptr, 0);
    }

    auto data   = piece->data() + (position - piece->lowerPosition());
    auto length = piece->upperPosition - position;

    return Block(data, length);
}
