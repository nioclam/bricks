/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#include "spiritfreer.h"
#include "spirit.h"

using namespace bricks;

void SpiritFreer::operator()(Spirit *spirit)
{
    spirit->destroy();
}
