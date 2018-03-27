/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#include "referable.h"

using namespace bricks;

Referable::Referable()
    : m_count(1)
{
}

Evil<Reference, ReferenceFreer> Referable::make()
{
    ++m_count;
    return std::move(Evil<Reference, ReferenceFreer>(this));
}

int Referable::referenceCount()
{
    return m_count;
}

void Referable::leave()
{
    if (0 == --m_count)
    {
        onReferenceless();
    }
}
