/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "lockfree.h"

using namespace bricks;

LockFree::LockFree()
    : m_freed()
{
    m_freed.store(true, std::memory_order_acquire);
}

void LockFree::lock()
{
    bool freed = true;

    while (
        !m_freed.compare_exchange_weak(
            freed,
            false,
            std::memory_order_release,
            std::memory_order_relaxed))
    {
        /* void loop */;
    }
}

bool LockFree::try_lock()
{
    bool freed = true;

    if (
        !m_freed.compare_exchange_weak(
            freed,
            false,
            std::memory_order_release,
            std::memory_order_relaxed))
    {
        return false;
    }

    return true;
}

void LockFree::unlock()
{
    m_freed.store(true, std::memory_order_acquire);
}
