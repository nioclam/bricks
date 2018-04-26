/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "lockfreestack.h"

using namespace bricks;

LockFreeStack::LockFreeStack()
    : m_singularity(nullptr)
{
}

LockFreeStack::LockFreeStack(Node *head)
    : m_singularity(head)
{
}

void LockFreeStack::hire(Node *node)
{
    node->m_next = m_singularity.load(std::memory_order_relaxed);

    while (
        !m_singularity.compare_exchange_weak(
            node->m_next,
            node,
            std::memory_order_release,
            std::memory_order_relaxed))
    {
        /* void loop */;
    }
}

Node *LockFreeStack::fire()
{
    auto node = m_singularity.load(std::memory_order_relaxed);

    while (
        !m_singularity.compare_exchange_weak(
            node,
            node->m_next,
            std::memory_order_release,
            std::memory_order_relaxed))
    {
        /* void loop */;
    }

    node->m_next = nullptr;
    return node;
}
