/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "queuelist.h"

using namespace bricks;

QueueList::QueueList()
    : m_singularity()
    , m_tail(&m_singularity)
{
}

void QueueList::push(Node *node)
{
    m_tail->link(node);
    m_tail = node;
}

Node *QueueList::pop()
{
    auto node = m_singularity.drop();

    if (m_tail == node) {
        m_tail = &m_singularity;
    }

    return node;
}
