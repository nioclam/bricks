/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
 
#include "referenceresource.h"

using namespace bricks;

ReferenceResource::ReferenceResource()
    : Reference()
{
}

void *ReferenceResource::onReferenceless()
{
    return release();
}
