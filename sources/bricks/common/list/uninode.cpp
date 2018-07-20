/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "uninode.h"

using namespace bricks;

UNINode::UNINode()
    : m_next(nullptr)
{
}

void UNINode::link(UNINode *next)
{
    auto stub = this;

    next->m_next = stub->m_next;
    stub->m_next = next;
}

UNINode *UNINode::drop()
{
    auto stub = this;
    auto next = this->m_next;

    if (next)
    {
        stub->m_next = next->m_next;
        next->m_next = nullptr;
    }

    return next;
}
