/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#include "resource.h"

using namespace bricks;

void *ResourceReleaser::release(Resource *resource)
{
    return resource->release();
}
