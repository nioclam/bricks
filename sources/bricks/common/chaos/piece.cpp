/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "piece.h"

using namespace bricks;

size_t Piece::length()
{
    return upperPosition() - lowerPosition();
}
