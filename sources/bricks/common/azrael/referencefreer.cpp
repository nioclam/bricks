/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#include "referencefreer.h"
#include "referable.h"

using namespace bricks;

void ReferenceFreer::operator()(Reference *reference)
{
    reference->leave();
}
