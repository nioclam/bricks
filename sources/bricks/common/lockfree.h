/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_LOCKFREE_H__
#define __BRICKS_POOL_LOCKFREE_H__ 1

#include <atomic>

// compatible with std::mutex

namespace bricks
{

class LockFree
{
public:
    LockFree();

public:
    void lock();
    bool try_lock();
    void unlock();

protected:
    std::atomic<bool> m_freed;
};

}

#endif /* #ifndef __BRICKS_POOL_LOCKFREE_H__ */
