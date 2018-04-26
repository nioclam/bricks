/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "resource.h"

using namespace bricks;

Resource::Resource()
    : m_next(nullptr)
{
}

Resource::Resource(Resource *next)
    : m_next(next)
{
}

void Resource::link(Resource *next)
{
    next->m_next = m_next;
    this->m_next = next;
}

Resource *Resource::drop()
{
    Resource *next = m_next;

    if (m_next)
    {
        m_next = m_next->m_next;
    }
    else
    {
        m_next = nullptr;
    }

    return next;
}
