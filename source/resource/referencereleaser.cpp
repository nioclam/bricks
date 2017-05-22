/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#include "reference.h"

using namespace bricks;

void *ReferenceReleaser::release(Reference *reference)
{
    return reference->decrease();
}
