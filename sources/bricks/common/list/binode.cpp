/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "binode.h"

using namespace bricks;

BINode::BINode()
    : m_prev(this)
    , m_next(this)
{
}

void BINode::enter(BINode *stub)
{
    auto next = stub->m_next;

    stub->m_next = this;
    this->m_prev = stub;
    this->m_next = next;
    next->m_prev = this;
}

void BINode::leave()
{
    auto prev = this->m_prev;
    auto next = this->m_next;

    prev->m_next = next;
    next->m_prev = prev;
    this->m_prev = this;
    this->m_next = this;
}
