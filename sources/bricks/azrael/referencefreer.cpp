/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#include "referencefreer.h"

using namespace bricks;

void ReferenceFreer::operator()(Reference *reference)
{
    reference->leave();
}
