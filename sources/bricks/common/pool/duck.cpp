/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "duck.h"

using namespace bricks;

Duck::Duck()
    : m_next(nullptr)
{
}

Duck::Duck(Duck *next)
    : m_next(next)
{
}

void Duck::link(Duck *next)
{
    next->m_next = m_next;
    this->m_next = next;
}

Duck *Duck::drop()
{
    Duck *next = m_next;

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
