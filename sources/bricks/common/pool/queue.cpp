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

Queue::Queue(Resource *head, Resource *tail)
    : m_singularity(head)
    , m_tail(tail)
{
}

void Queue::hire(Resource *resource)
{
    m_tail->link(resource);
    m_tail = resource;
}

Resource *Queue::fire()
{
    auto resource = m_singularity.drop();

    if (m_tail == resource) {
        m_tail = &m_singularity;
    }

    return resource;
}

Resource *Queue::head()
{
    return m_singularity.m_next;
}
