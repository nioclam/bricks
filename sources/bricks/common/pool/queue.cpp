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

Queue::Queue(Node *head, Node *tail)
    : m_singularity(head)
    , m_tail(tail)
{
}

void Queue::hire(Node *node)
{
    m_tail->hire(node);
    m_tail = node;
}

Node *Queue::fire()
{
    auto node = m_singularity.fire();

    if (m_tail == node) {
        m_tail = &m_singularity;
    }

    return node;
}
