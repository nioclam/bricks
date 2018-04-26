/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "node.h"

using namespace bricks;

Node::Node()
    : m_next(nullptr)
{
}

Node::Node(Node *next)
    : m_next(next)
{
}

void Node::link(Node *next)
{
    next->m_next = m_next;
    this->m_next = next;
}

Node *Node::drop()
{
    Node *next = m_next;

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
