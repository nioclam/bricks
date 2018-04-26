/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_LOCKFREESTACK_H__
#define __BRICKS_POOL_LOCKFREESTACK_H__ 1

#include <atomic>
#include "node.h"
#include "pool.h"

namespace bricks
{

class LockFreeStack : public Pool<Node>
{
public:
    LockFreeStack();
    LockFreeStack(Node *head);

public:
    virtual void hire(Node *node);
    virtual Node *fire();

protected:
    std::atomic<Node *> m_singularity;
};

}

#endif /* #ifndef __BRICKS_POOL_LOCKFREESTACK_H__ */
