/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#include "reference.h"

using namespace bricks;

Reference::Reference()
    : m_count(1)
{
}

Frozen<Reference> Reference::make()
{
    ++m_count;
    return Frozen<Reference>(this, singleton<ReferenceReleaser>());
}

int Reference::referenceCount()
{
    return m_count;
}

void *Reference::decrease()
{
    if (0 == --m_count)
    {
        return onReferenceless();
    }

    return NULL;
}
