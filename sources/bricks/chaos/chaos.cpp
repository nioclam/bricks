/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "chaos.h"
#include <utility>

using namespace bricks;

std::pair<byte_t *, size_t> Chaos::access(int position)
{
    auto piece = locate(position);

    if (nullptr == piece)
    {
        return Block(nullptr, 0);
    }

    auto data   = piece->data() + (position - piece->lowerPosition());
    auto length = piece->upperPosition - position;

    return Block(data, length);
}
