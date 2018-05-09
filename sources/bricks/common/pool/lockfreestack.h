/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_LOCKFREESTACK_H__
#define __BRICKS_POOL_LOCKFREESTACK_H__ 1

#include <atomic>
#include "resource.h"
#include "pool.h"

namespace bricks
{

class LockFreeStack : public Pool<Resource>
{
public:
    LockFreeStack();
    LockFreeStack(Resource *head);

public:
    virtual void hire(Resource *resource);
    virtual Resource *fire();

    /**
     * hire a list of resources
     */
    void hire(Resource *head, Resource *tail);

protected:
    std::atomic<Resource *> m_singularity;
};

}

#endif /* #ifndef __BRICKS_POOL_LOCKFREESTACK_H__ */
