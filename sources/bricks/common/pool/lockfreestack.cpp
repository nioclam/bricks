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

LockFreeStack::LockFreeStack(Duck *head)
    : m_singularity(head)
{
}

void LockFreeStack::hire(Duck *duck)
{
    duck->m_next = m_singularity.load(std::memory_order_relaxed);

    while (
        !m_singularity.compare_exchange_weak(
            duck->m_next,
            duck,
            std::memory_order_release,
            std::memory_order_relaxed))
    {
        /* void loop */;
    }
}

Duck *LockFreeStack::fire()
{
    auto head = m_singularity.load(std::memory_order_relaxed);

    while (
        nullptr != head &&
        !m_singularity.compare_exchange_weak(
            head,
            head->m_next,
            std::memory_order_release,
            std::memory_order_relaxed))
    {
        /* void loop */;
    }

    if (nullptr != head)
    {
        head->m_next = nullptr;
    }

    return head;
}

void LockFreeStack::hire(Duck *head, Duck *tail)
{
    tail->m_next = m_singularity.load(std::memory_order_relaxed);

    while (
        !m_singularity.compare_exchange_weak(
            tail->m_next,
            head,
            std::memory_order_release,
            std::memory_order_relaxed))
    {
        /* void loop */;
    }
}
