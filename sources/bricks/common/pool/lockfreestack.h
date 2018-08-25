/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_LOCKFREESTACK_H__
#define __BRICKS_POOL_LOCKFREESTACK_H__ 1

#include <atomic>
#include "duck.h"
#include "pool.h"

namespace bricks
{

class LockFreeStack : public Pool<Duck>
{
public:
    LockFreeStack();
    LockFreeStack(Duck *head);

public:
    virtual void hire(Duck *duck);
    virtual Duck *fire();

    /**
     * hire a list of ducks
     */
    void hire(Duck *head, Duck *tail);

protected:
    std::atomic<Duck *> m_singularity;
};

}

#endif /* #ifndef __BRICKS_POOL_LOCKFREESTACK_H__ */
