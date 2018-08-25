/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "queue.h"

using namespace bricks;

Queue::Queue()
    : m_singularity()
    , m_tail(&m_singularity)
{
}

Queue::Queue(Duck *head, Duck *tail)
    : m_singularity(head)
    , m_tail(tail)
{
}

void Queue::hire(Duck *duck)
{
    m_tail->link(duck);
    m_tail = duck;
}

Duck *Queue::fire()
{
    auto duck = m_singularity.drop();

    if (m_tail == duck) {
        m_tail = &m_singularity;
    }

    return duck;
}

Duck *Queue::head()
{
    return m_singularity.m_next;
}
