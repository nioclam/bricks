/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "node.h"

using namespace bricks;

Node::Node()
    : m_prev(this)
    , m_next(this)
{
}

void Node::enter(Node *stub)
{
    auto next = stub->m_next;

    stub->m_next = this;
    this->m_prev = stub;
    this->m_next = next;
    next->m_prev = this;
}

void Node::leave()
{
    auto prev = this->m_prev;
    auto next = this->m_next;

    prev->m_next = next;
    next->m_prev = prev;
    this->m_prev = this;
    this->m_next = this;
}
