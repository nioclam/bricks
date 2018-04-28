/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include <stdio.h>
#include "chaos.h"

using namespace bricks;

Block Chaos::access(size_t position)
{
    Azrael<Piece> piece;

    if (-1 == piece.redeem(locate(position)))
    {
        fprintf(stderr, "Chaos#size(%zu)::access(%zu)", size(), position);
        return Block(nullptr, 0);
    }

    auto data   = piece->data() + (position - piece->lowerPosition());
    auto length = piece->upperPosition() - position;

    return Block(data, length);
}
