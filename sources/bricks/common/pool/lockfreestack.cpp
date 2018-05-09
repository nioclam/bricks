﻿/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "lockfreestack.h"

using namespace bricks;

LockFreeStack::LockFreeStack()
    : m_singularity(nullptr)
{
}

LockFreeStack::LockFreeStack(Resource *head)
    : m_singularity(head)
{
}

void LockFreeStack::hire(Resource *resource)
{
    resource->m_next = m_singularity.load(std::memory_order_relaxed);

    while (
        !m_singularity.compare_exchange_weak(
            resource->m_next,
            resource,
            std::memory_order_release,
            std::memory_order_relaxed))
    {
        /* void loop */;
    }
}

Resource *LockFreeStack::fire()
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

void LockFreeStack::hire(Resource *head, Resource *tail)
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
